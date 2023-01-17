<?php
	session_start();	
// Include config file
	require_once "config.php";
    $DUPLICATE_KEY_ERROR = 1062;
 
// Define variables and initialize with empty values
$Dependent_name = $Bdate = $Bdate1 = $Relationship = $Sex = "";
$Dependent_name_err = $Relationship_err = $Sex_err = "" ;
// Form default values

if(isset($_GET["Essn"]) && !empty(trim($_GET["Essn"])) && isset($_GET["Dependent_name"]) && !empty(trim($_GET["Dependent_name"]))){
	$_SESSION["Essn"] = $_GET["Essn"];
    $_SESSION["Dependent_name"] = $_GET["Dependent_name"];

    // Prepare a select statement
    $sql1 = "SELECT * FROM DEPENDENT WHERE Essn = ? AND Dependent_name = ?";
  
    if($stmt1 = mysqli_prepare($link, $sql1)){
        // Bind variables to the prepared statement as parameters
        mysqli_stmt_bind_param($stmt1, "ss", $param_Essn, $param_Dependent_name);      
        // Set parameters
       $param_Ssn = trim($_GET["Essn"]);

        // Attempt to execute the prepared statement
        if(mysqli_stmt_execute($stmt1)){
            $result1 = mysqli_stmt_get_result($stmt1);
			if(mysqli_num_rows($result1) > 0){

				$row = mysqli_fetch_array($result1);

				$Essn = $row['Essn'];
				$Dependent_name = $row['Dependent_name'];
				$Sex = $row['Sex'];
				$Bdate = $row['Bdate'];
				$Relationship = $row['Relationship'];
			}
		}
	}
}

 
// Post information about the employee when the form is submitted
// Processing form data when form is submitted
if($_SERVER["REQUEST_METHOD"] == "POST"){
    // the id is hidden and can not be changed
    $Essn = $_SESSION["Essn"];
    $Original_dependent_name = $_SESSION["Dependent_name"];
    // Validate form data this is similar to the create Employee file
    // Validate name
    $Dependent_name = trim($_POST["Dependent_name"]);
    if(empty($Dependent_name)){
        $Dependent_name_err = "Please enter a Dependent name.";
    } elseif(!filter_var($Dependent_name, FILTER_VALIDATE_REGEXP, array("options"=>array("regexp"=>"/^[a-zA-Z\s]+$/")))){
        $Dependent_name_err = "Please enter a valid Dependent name.";
    }
    // Validate Sex
    $Sex = trim($_POST["Sex"]);
    if(empty($Sex)){
        $Sex_err = "Please enter a Sex.";     
    }
	// Validate Bdate
    $Bdate = trim($_POST["Bdate"]);
    if(empty($Bdate)){
        $Bdate_err = "Please enter a Birthdate.";    	
	}
	// Validate Relationship
    $Relationship = trim($_POST["Relationship"]);
    if(empty($Relationship)){
        $Relationship_err = "Please enter a Relationship.";    	
	}

    // Check input errors before inserting into database
    if(empty($Dependent_name_err) && empty($Sex_err) && empty($Bdate_err) && empty($Relationship_err)){
        // Prepare an update statement
        $sql = "UPDATE DEPENDENT SET Dependent_name=?, Sex=?, Bdate = ?, Relationship = ? WHERE Essn=? AND Dependent_name=?";
    
        if($stmt = mysqli_prepare($link, $sql)){
            // Bind variables to the prepared statement as parameters
            mysqli_stmt_bind_param($stmt, "ssssss", $param_Dependent_name, $param_Sex, $param_Bdate, $param_Relationship, $param_Essn, $param_Original_dependent_name);
            
            // Set parameters
			$param_Dependent_name = $Dependent_name;            
			$param_Sex = $Sex;
            $param_Bdate = $Bdate;
            $param_Relationship = $Relationship;
            $param_Essn = $Essn;
            $param_Original_dependent_name = $Original_dependent_name;
            
            // Attempt to execute the prepared statement
            if(mysqli_stmt_execute($stmt)){
                // Records updated successfully. Redirect to landing page
                header("location: program2_viewDependent.php?Ssn=". $param_Essn);
                exit();
            } else if($stmt -> errno == $DUPLICATE_KEY_ERROR){
                $Dependent_name_err = "Dependent name already exists.";
            } else{
                echo "Error while updating dependent | " . $stmt -> errno;
            }
        }        
        // Close statement
        mysqli_stmt_close($stmt);
    }
    
    // Close connection
    mysqli_close($link);
} else {

    // Check existence of sID parameter before processing further
	// Form default values

	if(isset($_GET["Essn"]) && !empty(trim($_GET["Essn"])) && isset($_GET["Dependent_name"]) && !empty(trim($_GET["Dependent_name"]))){
        $_SESSION["Essn"] = $_GET["Essn"];
        $_SESSION["Dependent_name"] = $_GET["Dependent_name"];
    
		// Prepare a select statement
		$sql1 = "SELECT * FROM DEPENDENT WHERE Essn = ? AND Dependent_name = ?";
  
		if($stmt1 = mysqli_prepare($link, $sql1)){
			// Bind variables to the prepared statement as parameters
			mysqli_stmt_bind_param($stmt1, "ss", $param_Essn, $param_Original_dependent_name);      
			// Set parameters
		$param_Essn = trim($_GET["Essn"]);
		$param_Original_dependent_name = trim($_GET["Dependent_name"]);

			// Attempt to execute the prepared statement
			if(mysqli_stmt_execute($stmt1)){
				$result1 = mysqli_stmt_get_result($stmt1);
				if(mysqli_num_rows($result1) == 1){

					$row = mysqli_fetch_array($result1);

					$Essn = $row['Essn'];
					$Dependent_name = $row['Dependent_name'];
					$Bdate = $row['Bdate'];
					$Sex = $row['Sex'];
					$Relationship = $row['Relationship'];
				} else{
					// URL doesn't contain valid id. Redirect to error page
					header("location: error1.php");
					exit();
				}
                
			} else{
				echo "Error in ESSN or Dependent name while updating";
			}
		
		}
			// Close statement
			mysqli_stmt_close($stmt);
        
			// Close connection
			mysqli_close($link);
	}  else{
        // URL doesn't contain id parameter. Redirect to error page
        header("location: error2.php");
        exit();
	}	
}
?>
 
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>College DB</title>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.css">
    <style type="text/css">
        .wrapper{
            width: 500px;
            margin: 0 auto;
        }
    </style>
</head>
<body>
    <div class="wrapper">
        <div class="container-fluid">
            <div class="row">
                <div class="col-md-12">
                    <div class="page-header">
                        <h3>Update Record for SSN =  <?php echo $_GET["Essn"]; ?> </H3>
                    </div>
                    <p>Please edit the input values and submit to update.
                    <form action="<?php echo htmlspecialchars(basename($_SERVER['REQUEST_URI'])); ?>" method="post">
                        <input type="hidden" name="Essn" value="<?php echo ($_SESSION["Essn"]); ?>"/>
						<div class="form-group <?php echo (!empty($Dependent_name_err)) ? 'has-error' : ''; ?>">
                            <label>Dependent name</label>
                            <input type="text" name="Dependent_name" class="form-control" value="<?php echo $Dependent_name; ?>">
                            <span class="help-block"><?php echo $Dependent_name_err;?></span>
                        </div>
						<div class="form-group <?php echo (!empty($Relationship_err)) ? 'has-error' : ''; ?>">
                            <label>Relationship</label>
                            <input type="text" name="Relationship" class="form-control" value="<?php echo $Relationship; ?>">
                            <span class="help-block"><?php echo $Relationship_err;?></span>
                        </div>
						<div class="form-group <?php echo (!empty($Sex_err)) ? 'has-error' : ''; ?>">
                            <label>Sex</label>
                            <input type="text" name="Sex" class="form-control" value="<?php echo $Sex; ?>">
                            <span class="help-block"><?php echo $Sex_err;?></span>
                        </div>
						<div class="form-group <?php echo (!empty($Birth_err)) ? 'has-error' : ''; ?>">
                            <label>Birth date</label>
                            <input type="date" name="Bdate" class="form-control" value="<?php echo $Bdate; ?>">
                            <span class="help-block"><?php echo $Birth_err;?></span>
                        </div>
                        <input type="submit" class="btn btn-primary" value="Submit">
                        <a href="program2_viewDependent.php?Ssn=<?php echo ($_SESSION["Essn"]); ?>" class="btn btn-default">Cancel</a>
                    </form>
                </div>
            </div>        
        </div>
    </div>
</body>
</html>