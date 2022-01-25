<?php   
    //create username and password
    session_start();
    if(isset($_POST['create'])){
        $servername = "localhost";
        //$conn = new PDO("mysql:host=$servername;dbname=users", $_SESSION['user'], $_SESSION['password']);
      // $sql = "INSERT INTO users(username)
        //VALUES ('John');";

          try {
            $conn = new PDO("mysql:host=$servername;dbname=users", $_SESSION['user'], $_SESSION['password']);
            // set the PDO error mode to exception
            $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
            $user =$_POST['newuser'];
            $pwd =$_POST['newpwd'];
            $sql = "INSERT INTO users(username,password) VALUES ('$user', '$pwd');";
            if ($conn->query($sql)) {
              echo '<script type ="text/JavaScript">';  
              echo 'alert("Usuario creado")';  
              echo '</script>';  
            } else {
              echo "<h2 class='failed'>ERROR</h2>";
            }
          } catch(PDOException $e) {
            echo "<h2 class='failed'>ERROR</h2>";
          }
            /*if ($conn->query($sql) === TRUE) {
              echo "<h3 class='failed'>Nombre de Usuario o Password incorrecto</h3>";
            } else {
              echo "Error: " . $sql . "<br>" . $conn->error;
            }*/
      }
      if(isset($_POST['resetpwd'])){
        $servername = "localhost";
          try {
            $conn = new PDO("mysql:host=$servername;dbname=users", $_SESSION['user'], $_SESSION['password']);
            // set the PDO error mode to exception
            $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
            $user =$_POST['ruser'];
            $pwd =$_POST['rpwd'];
            $sql = "UPDATE users SET password='$pwd' WHERE username='$user';";
            //$conn->query($sql);
           $stmt = $conn->prepare($sql);

          // execute the query
           if($stmt->execute()){
            echo '<script type ="text/JavaScript">';  
            echo 'alert("Password updated")';  
            echo '</script>';
           }
           else{
            echo '<script type ="text/JavaScript">';  
            echo 'alert("User not found")';  
            echo '</script>';
           }
            
          } catch(PDOException $e) {
            echo "<h2 class='failed'>ERROR</h2>";
          }
            /*if ($conn->query($sql) === TRUE) {
              echo "<h3 class='failed'>Nombre de Usuario o Password incorrecto</h3>";
            } else {
              echo "Error: " . $sql . "<br>" . $conn->error;
            }*/
      }
      if(isset($_POST['deleteu'])){
        $servername = "localhost";
          try {
            $conn = new PDO("mysql:host=$servername;dbname=users", $_SESSION['user'], $_SESSION['password']);
            // set the PDO error mode to exception
            $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
            $user =$_POST['duser'];
            $sql = "DELETE FROM users WHERE username='$user';";
    
          // execute the query
           if($conn->exec($sql)){
            echo '<script type ="text/JavaScript">';  
            echo 'alert("User deleted")';  
            echo '</script>';
           }else{
            echo '<script type ="text/JavaScript">';  
            echo 'alert("User not found")';  
            echo '</script>';
           }
            
          } catch(PDOException $e) {
            echo "<h2 class='failed'>ERROR</h2>";
          }

      }

      

?>