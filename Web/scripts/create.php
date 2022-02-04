<?php   
    session_start();
    try{
      if(isset($_COOKIE['state'])){
        if(isset($_POST['create'])){
          $servername = $_SESSION['server'];
            try {
              $conn = new PDO("mysql:host=$servername;dbname=users", $_SESSION['user'], $_SESSION['password']);
              // set the PDO error mode to exception
              $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
              $user =$_POST['newuser'];
              $pwd =$_POST['newpwd'];
              $encrypted_password = md5($pwd);
              $sql = "INSERT INTO users(username,password) VALUES ('$user', '$encrypted_password');";
              $sql2 = "SELECT * FROM users WHERE username='".$user."';";
              $result = $conn->query($sql2);
              if($result->rowCount()<1){
                if ($conn->query($sql)) {
                  echo '<h3 id="createSuccess">Usuario Creado</h3>'; 
            
                  echo '<h1 hidden id="refreshform" class="formcrear"></h1>';
                }else{
                  echo "<h2 class='failed'>ERROR</h2>";
                }
              } else {
                echo '<h1 hidden id="refreshform" class="formcrear"></h1>';
                echo '<h2 id="exists">The user already exists</h2>';
              }
            } catch(PDOException $e) {
              echo "<h2 class='failed'>ERROR</h2>";
            }
  
        }
        if(isset($_POST['resetpwd'])){
          $servername = $_SESSION['server'];
            try {
              $conn = new PDO("mysql:host=$servername;dbname=users", $_SESSION['user'], $_SESSION['password']);
              // set the PDO error mode to exception
              $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
              $user =$_POST['ruser'];
              $pwd =$_POST['rpwd'];
              $encrypted_password = md5($pwd);
              $sql = "UPDATE users SET password='$encrypted_password' WHERE username='$user';";
              $result = $conn->query($sql);
              //$conn->query($sql);
              $stmt = $conn->prepare($sql);
  
            // execute the query
             if($stmt->execute() && $result->rowCount()>0){
              echo '<h3 id="resetSuccess">Password updated</h3>'; 
            
              echo '<h1 hidden id="refreshform" class="formreset"></h1>';
             }
             else{
              echo '<h1 hidden id="refreshform" class="formreset"></h1>';
                echo '<h2 id="exists">user not found</h2>';
             }
              
            } catch(PDOException $e) {
              echo "<h2 class='failed'>ERROR</h2>";
            }
  
        }
        if(isset($_POST['deleteu'])){
          $servername = $_SESSION['server'];
            try {
              $conn = new PDO("mysql:host=$servername;dbname=users", $_SESSION['user'], $_SESSION['password']);
              // set the PDO error mode to exception
              $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
              $user =$_POST['duser'];
              $sql = "DELETE FROM users WHERE username='$user';";
      
            // execute the query
             if($conn->exec($sql)){
              echo '<h3 id="deleteSuccess">User deleted</h3>'; 
            
              echo '<h1 hidden id="refreshform" class="formdelete"></h1>';
             }else{
              echo '<h1 hidden id="refreshform" class="formdelete"></h1>';
                echo '<h2 id="exists">user not found</h2>';
             }
              
            } catch(PDOException $e) {
              echo "<h2 class='failed'>ERROR</h2>";
            }
        }
    }else{

      header("Location: ./index.php");

    }
  }catch(PDOException $e){
    echo ' ';
  }
    
?>