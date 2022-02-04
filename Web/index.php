<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Login</title>
    <link href="https://fonts.googleapis.com/css?family=Amatic+SC|Raleway:100,200,600,700" rel="stylesheet">
    <link rel="stylesheet" href="./styles/styles.css">
</head>
<body>
    <div class="logo"><img src="./img/logo.png" alt="logo"></div>
    <?php require './scripts/db.php' ?>
    <form method='POST'>
        <input type="text" placeholder="Nombre de Usuario" id="usuario" name = 'user' class='data' required pattern='.*'>
        <input type="password" id="password" placeholder="Contraseña" class='data' name='password' required pattern='.*'>
        <input type="submit" value="login" class='button' name="submito">
    </form>
</body>


</html>
