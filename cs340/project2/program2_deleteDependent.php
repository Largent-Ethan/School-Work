<?php
session_start();
if(isset($_GET["Essn"]) && !empty(trim($_GET["Essn"])) && isset($_GET["Dependent_name"]) && !empty(trim($_GET["Dependent_name"]))){
	$_SESSION["Essn"] = $_GET["Essn"];
    $_SESSION["Dependent_name"] = $_GET["Dependent_name"];
}

require_once "config.php";
if ($_SERVER["REQUEST_METHOD"] == "POST") {
	if (empty($_SESSION["Essn"])) {
		$_SESSION["Essn"] = $_POST["Essn"];
	}
	if (empty($_SESSION["Dependent_name"])) {
		$_SESSION["Dependent_name"] = $_POST["Dependent_name"];
	}
	if(isset($_SESSION["Essn"]) && !empty($_SESSION["Essn"]) && isset($_SESSION["Dependent_name"]) && !empty($_SESSION["Dependent_name"])){ 
		$Essn = $_SESSION['Essn'];
		$Dependent_name = $_SESSION['Dependent_name'];
		// Prepare a delete statement
		$sql = "DELETE FROM DEPENDENT WHERE Essn = ? AND Dependent_name = ?";

		if($stmt = mysqli_prepare($link, $sql)){
		// Bind variables to the prepared statement as parameters
			mysqli_stmt_bind_param($stmt, "ss", $param_Essn, $param_Dependent_name);

			// Set parameters
			$param_Essn = $Essn;
			$param_Dependent_name = $Dependent_name;
   
			// Attempt to execute the prepared statement
			if(mysqli_stmt_execute($stmt)){
				// Records deleted successfully. Redirect to landing page
				header("location: program2_viewDependent.php?Ssn=". $param_Essn);
				exit();
			} else{
				echo "Error deleting the employee";
			}
		}
	}
	// Close statement
	mysqli_stmt_close($stmt);

	// Close connection
	mysqli_close($link);
} else{
	// Check existence of id parameter
	if(empty(trim($_GET["Essn"])) || empty(trim($_GET["Dependent_name"]))){
		// URL doesn't contain id parameter. Redirect to error page
		header("location: error.php");
		exit();
	}
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>View Record</title>
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
                        <h1>Delete Record</h1>
                    </div>
                    <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post">
                        <div class="alert alert-danger fade in">
                            <input type="hidden" name="Essn" value="<?php echo ($_SESSION["Essn"]); ?>"/>
                            <input type="hidden" name="Dependent_name" value="<?php echo ($_SESSION["Dependent_name"]); ?>"/>
                            <p>Are you sure you want to delete the record for employee <?php echo ($_SESSION["Essn"]); ?> dependent name <?php echo ($_SESSION["Dependent_name"]); ?>?</p><br>
                                <input type="submit" value="Yes" class="btn btn-danger">
                                <a href="program2_viewDependent.php?Ssn=<?php echo ($_SESSION["Essn"]); ?>" class="btn btn-default">No</a>
                            </p>
                        </div>
                    </form>
                </div>
            </div>        
        </div>
    </div>
</body>
</html>