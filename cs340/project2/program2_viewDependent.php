<?php
	session_start();
    require_once "config.php";
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>View Dependents</title>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
	<style type="text/css">
        .wrapper{
            width: 70%;
            margin:0 auto;
        }
        .page-header h2{
            margin-top: 0;
        }
        table tr td:last-child a{
            margin-right: 15px;
        }
    </style>
        <script type="text/javascript">
        $(document).ready(function(){
            $('[data-toggle="tooltip"]').tooltip();   
        });
    </script>
</head>
<body>
    <div class="wrapper">
        <div class="container-fluid">
            <div class="row">
                <div class="col-md-12">
                    <div class="page-header clearfix">
                        <?php echo "<h2 class='pull-left'>Dependent list for SSN = " . $_SESSION["Ssn"] ."</h2>" ?>
                        <a href="program2_createDependent.php?Essn=<?php echo ($_SESSION["Essn"]); ?>" class="btn btn-success pull-right">Add New Dependent</a>
                    </div>
<?php
if(isset($_GET["Ssn"]) && !empty(trim($_GET["Ssn"]))){
	$_SESSION["Ssn"] = $_GET["Ssn"];
}

$param_Ssn = ($_SESSION["Ssn"]);

if(isset($_SESSION["Ssn"]) ){
    $sql = "SELECT Essn,Dependent_name,Sex,Bdate,Relationship
    	FROM DEPENDENT
        WHERE Essn = $param_Ssn";
                    
    if($result = mysqli_query($link, $sql)){
        if(mysqli_num_rows($result) > 0){
            echo "<table class='table table-bordered table-striped'>";
                echo "<thead>";
                    echo "<tr>";
                        echo "<th width=9%>Dependent's Name</th>";
                        echo "<th width=10%>Sex</th>";
                        echo "<th width=12%>Birthdate</th>";
                        echo "<th width=9%>Relationship</th>";
                        echo "<th width=8%>Action</th>";
                    echo "</tr>";
                echo "</thead>";
                echo "<tbody>";
                while($row = mysqli_fetch_array($result)){
                    echo "<tr>";
                        echo "<td>" . $row['Dependent_name'] . "</td>";							
                        echo "<td>" . $row['Sex'] . "</td>";
						echo "<td>" . $row['Bdate'] . "</td>";
                        echo "<td>" . $row['Relationship'] . "</td>";
                        echo "<td>";
                            echo "<a href='program2_updateDependent.php?Essn=". $row['Essn'] ."&Dependent_name=". $row['Dependent_name'] ."' title='Update Dependent' data-toggle='tooltip'><span class='glyphicon glyphicon-pencil'></span></a>";
                            echo "<a href='program2_deleteDependent.php?Essn=". $row['Essn'] ."&Dependent_name=". $row['Dependent_name'] ."' title='Delete Dependent' data-toggle='tooltip'><span class='glyphicon glyphicon-trash'></span></a>";
                        echo "</td>";
                    echo "</tr>";
                }
                echo "</tbody>";                            
            echo "</table>";
            mysqli_free_result($result);
        } else{
            echo "<p class='lead'><em>No dependents were found.</em></p>";
        }
    } else{
        echo "ERROR: Could not able to execute $sql. <br>" . mysqli_error($link);
    }
    mysqli_close($link);
} else{
    header("location: error.php");
    exit();
}
?>					                 
					
	<p><a href="index.php" class="btn btn-primary">Back</a></p>
</div>
</body>
</html>