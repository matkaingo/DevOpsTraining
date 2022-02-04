<?php
        require __DIR__.'/vendor/autoload.php';
        $dotenv = Dotenv\Dotenv::createImmutable(__DIR__);
        $dotenv->load();
        if(isset($_POST['submito'])){ //post submitted
            $servername = $_ENV["SERVER"];
            $username = $_POST['user'];
            $password = $_POST['password'];
            try {
                $conn = new PDO("mysql:host=$servername;dbname=users", $_ENV["USER"], $_ENV["PWD"]);
                // set the PDO error mode to exception
                session_start();
                $_SESSION['user'] = $_ENV["USER"];
                $_SESSION['password'] = $_ENV["USER"];
                $_SESSION['server'] = $_ENV["SERVER"];
                $encrypted_password = md5($password);
                $sql = "SELECT * FROM users WHERE username='".$username."' AND password='".$encrypted_password."';";
                $result = $conn->query($sql);
                if($result->rowCount()>0){
                  
                  $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
                  header("Location: ./management.php");
                  setcookie('state','online',time()+1800);
                }else{
                  echo "<h2 class='failed'>Nombre de Usuario o Password equivocado</h2>";
                }
                
              } catch(PDOException $e) {
                echo "<h2 class='failed'>Error de conexion</h2>".$e;
              }
        }
    ?>











































































































    
