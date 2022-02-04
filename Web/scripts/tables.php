<?php
    echo "<table style='border: solid 1px black;'>";
      echo "<tr><thead><th>Usernames</th></thead></tr>";
    class TableRows extends RecursiveIteratorIterator {
        function __construct($it) {
          parent::__construct($it, self::LEAVES_ONLY);
        }

        function current() {
          return "<td style='width:150px;border:1px solid black;'>" . parent::current(). "</td>";
        }function beginChildren() {
          echo "<tr>";
        }
      
        function endChildren() {
          echo "</tr>" . "\n";
        }
      }
      try {
        $servername = "dev-ohio-phpapp-db.c90htr5rphcp.us-east-2.rds.amazonaws.com";
        $conn = new PDO("mysql:host=$servername;dbname=users", $_SESSION['user'], $_SESSION['password']);
        $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        $stmt = $conn->prepare("SELECT username FROM users");
        $stmt->execute();
      
        // set the resulting array to associative
        $result = $stmt->setFetchMode(PDO::FETCH_ASSOC);
        foreach(new TableRows(new RecursiveArrayIterator($stmt->fetchAll())) as $k=>$v) {
          echo $v;
        }
      } catch(PDOException $e) {
        echo "Error: " . $e->getMessage();
      }
      $conn = null;
      echo "</table>";

      ?>