<?php
        if(isset($_POST['submito'])){ //post submitted
            $servername = "localhost";
            $username = $_POST['user'];
            $password = $_POST['password'];
            $_SESSION['user'] = $username;
            $_SESSION['password'] = $password;
            try {
                $conn = new PDO("mysql:host=$servername;dbname=users", $username, $password);
                // set the PDO error mode to exception
                $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
                header("Location: http://localhost/first/management.php");
              } catch(PDOException $e) {
                echo "<h2 class='failed'>Nombre de Usuario o Password incorrecto</h2>";
              }
        }
    ?>
