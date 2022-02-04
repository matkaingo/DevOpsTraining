<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>management</title>
    <link href="https://fonts.googleapis.com/css?family=Amatic+SC|Raleway:100,200,600,700" rel="stylesheet">
    <link rel="stylesheet" href="./styles/styles.css?v=<?php echo time(); ?>">
    <script src="./scripts/scripts.js?v=<?php echo time(); ?>"></script>
</head>
<body onload="mainForm()">
    <header> <!--Un nav bar para seleccionar entre login.html y management.html -->
        <nav class="navigation">
            <ul>
                <li id="createuser">Crear Usuario</li>
                <li id='reset'>Reiniciar password</li>
                <li id='deleteU'>Eliminar Usuario</li>
                <li id='list'>Listar Usuarios</li>
                <li id='pls'>logout</li>
            </ul>
        </nav>

    </header>
    <h1 hidden id="currentform" class="formhandler"></h1>
    <?php require './scripts/create.php' ?>
    <section class="mostrar" id="main">
        <h1>Bienvenidos a la mejor Web del planeta tierra y marte</h1>
        <img src="./img/squidward.gif" alt="squidward dancing">
    </section>

    <!--Create User-->
    <section id='create_user' class="ocultar">
        <h1>Crear Usuario</h1>
        <form  method="POST" id='create_form' name='form1'>
            <input type="text" placeholder="Nombre de Usuario" name='newuser' class='data' required pattern='.*'>
            <input type="password" id="newpwd" name='newpwd' placeholder="Contraseña" class='data' pattern="(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).{8,}" 
            title="Must contain at least one number and one uppercase and lowercase letter, and at least 8 or more characters" required>
            <input type="submit" value="Crear Usuario" name='create' id ='create' class='button'>
        </form>

    </section>
    <section id='reset_pwd' class="ocultar">
        <form method="POST">
            <h1>Reiniciar password</h1>
            <input type="text" placeholder="Nombre de Usuario" name='ruser' class='data' required pattern='.*'>
            <input type="password" placeholder="Contraseña" class='data' name='rpwd' pattern="(?=.*\d)(?=.*[a-z])(?=.*[A-Z]).{8,}" 
            title="Must contain at least one number and one uppercase and lowercase letter, and at least 8 or more characters" required>
            <input type="submit" value="Reiniciar Password" name='resetpwd' class='button'>
        </form>
    </section>
    
    <section id='delete_user' class="ocultar">
        <form method="POST">
            <h1>Eliminar Usuario</h1>
            <input type="text" placeholder="Nombre de Usuario" name='duser' class='data' required pattern='.*'>
            <input type="submit" value="Eliminar usuario" name='deleteu'class='button'>
        </form>
    </section>
    
    <section id='list_user' class="ocultar">
        <?php require './scripts/tables.php' ?>
        </form>
    </section>
    
    
</body>
<script src="./scripts/styles.js?v=<?php echo time(); ?>"></script>
</html>