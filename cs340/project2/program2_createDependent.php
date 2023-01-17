<?php

session_start();
$DUPLICATE_KEY_ERROR = 1062;
// Include config file
if(isset($_GET["Essn"]) && !empty(trim($_GET["Essn"]))){
	$_SESSION["Essn"] = $_GET["Essn"];
}
require_once "config.php";
 
// Define variables and initialize with empty values
$Dependent_name = $Bdate = $Relationship = $Sex = "";
$Dependent_name_err = $Bdate_err = $Relationship_err = $Sex_err = "" ;
 
// Processing form data when form is submitted
if($_SERVER["REQUEST_METHOD"] == "POST"){
    if (empty($_SESSION["Essn"])) {
        $_SESSION["Essn"] = $_POST["Essn"];
    }
    // Validate Dependent name
    $Dependent_name = trim($_POST["Dependent_name"]);
    if(empty($Dependent_name)){
        $Dependent_name_err = "Please enter a Dependent name.";
    } elseif(!filter_var($Dependent_name, FILTER_VALIDATE_REGEXP, array("options"=>array("regexp"=>"/^[a-zA-Z\s]+$/")))){
        $Dependent_name_err = "Please enter a valid Dependent name.";
    } else if(1/*Duplicate name */){
        $Dependent_name_err = "Dependent name already exists.";
    }
	// Validate Relationship
    $Relationship = trim($_POST["Relationship"]);
    if(empty($Relationship)){
        $Relationship_err = "Please enter a Relationship.";     
    }
	// Validate Sex
    $Sex = trim($_POST["Sex"]);
    if(empty($Sex)){
        $Sex_err = "Please enter a Sex.";     
    }
	// Validate Birthdate
    $Bdate = trim($_POST["Bdate"]);
    if(empty($Bdate)){
        $Bdate_err = "Please enter a Birthdate.";     
    }
    // Check input errors before inserting in database
    if(empty($Dependent_name_err) && empty($Bdate_err) && empty($Relationship_err) && empty($Sex_err) && isset($_SESSION["Essn"]) && !empty($_SESSION["Essn"])){
        // Prepare an insert statement
		$Essn = $_SESSION['Essn'];
        $sql = "INSERT INTO DEPENDENT (Essn, Dependent_name, Sex, Bdate, Relationship) 
		        VALUES (?, ?, ?, ?, ?)";
         
        if($stmt = mysqli_prepare($link, $sql)){
            // Bind variables to the prepared statement as parameters
            mysqli_stmt_bind_param($stmt, "sssss", $param_Essn, $param_Dependent_name, $param_Sex, $param_Bdate, $param_Relationship);
            
            // Set parameters
            $param_Essn = $Essn;
			$param_Dependent_name = $Dependent_name;
			$param_Relationship = $Relationship;
			$param_Sex = $Sex;
			$param_Bdate = $Bdate;
            
            // Attempt to execute the prepared statement
            if(mysqli_stmt_execute($stmt)){
                // Records created successfully. Redirect to landing page
				header("location: program2_viewDependent.php?Ssn=". $param_Essn);
				exit();
            } else if($stmt -> errno == $DUPLICATE_KEY_ERROR){
                $Dependent_name_err = "Dependent name already exists.";
            } else{
                echo "Error while creating new dependent";
            }
        }
         
        // Close statement
        mysqli_stmt_close($stmt);
    }

    // Close connection
    mysqli_close($link);
}
?>
 
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Create Dependent</title>
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
                        <h2>Create a Dependent</h2>
                    </div>
                    <?php echo "<h3>Employee SSN = " . ($_SESSION["Essn"]) . "</h3>";?>
                    <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post">
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
                            <input type="date" name="Bdate" class="form-control" value="<?php echo date('Y-m-d'); ?>">
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