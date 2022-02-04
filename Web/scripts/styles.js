const create = document.getElementById('createuser');
const create_user = document.getElementById('create_user');
const reset = document.getElementById("reset");
const reset_pwd = document.getElementById('reset_pwd');
const deleteU = document.getElementById("deleteU");
const delete_user = document.getElementById('delete_user');
const list = document.getElementById("list");
const list_user = document.getElementById('list_user');
const mostrar = document.getElementById("main");
const logout = document.getElementById("pls");
const createMssg =document.getElementById("createSuccess");
const deleteMsg =document.getElementById("deleteSuccess");
const resetMssg =document.getElementById("resetSuccess");
const exists = document.getElementById("exists");



logout.addEventListener('click',()=>{
    location.replace("./index.php");
    var res = document.cookie;
    var multiple = res.split(";");
    for(var i = 0; i < multiple.length; i++) {
        var key = multiple[i].split("=");
        document.cookie = key[0]+" =; expires = Thu, 01 Jan 1970 00:00:00 UTC";}
})




create.addEventListener('click',()=>{
    console.log("Clickeado");
    create_user.className = "mostrar";
    reset_pwd.className = "ocultar";
    delete_user.className = "ocultar";
    list_user.className = "ocultar";
    mostrar.className = "ocultar";
    create.style.opacity = 1;
    create.style.borderBottom = "5px solid";
    create.style.borderRadius = "5px";
    reset.style.opacity = 0.4;
    reset.style.borderBottom = 0;
    deleteU.style.opacity = 0.4;
    deleteU.style.borderBottom = 0;
    list.style.opacity = 0.4;
    list.style.borderBottom = 0;
    try{
        resetMssg.className = "ocultar";
    }catch{

    }try{
        deleteMsg.className = "ocultar";
    }catch{

    }try{
        exists.className = "ocultar";
    }catch{

    }
})
reset.addEventListener('click',()=>{
    create_user.className = "ocultar";
    reset_pwd.className = "mostrar";
    delete_user.className = "ocultar";
    list_user.className = "ocultar";
    mostrar.className = "ocultar";
    reset.style.opacity = 1;
    reset.style.borderBottom = "5px solid";
    reset.style.borderRadius = "5px";
    create.style.opacity = 0.4;
    create.style.borderBottom = 0;
    deleteU.style.opacity = 0.4;
    deleteU.style.borderBottom = 0;
    list.style.opacity = 0.4;
    list.style.borderBottom = 0;
    try{
        createMssg.className = "ocultar";
    }catch{

    }try{
        deleteMsg.className = "ocultar";
    }catch{

    }try{
        exists.className = "ocultar";
    }catch{

    }
})
deleteU.addEventListener('click',()=>{
    create_user.className = "ocultar";
    reset_pwd.className = "ocultar";
    delete_user.className = "mostrar";
    list_user.className = "ocultar";
    mostrar.className = "ocultar";
    deleteU.style.opacity = 1;
    deleteU.style.borderBottom = "5px solid";
    deleteU.style.borderRadius = "5px";
    reset.style.opacity = 0.4;
    reset.style.borderBottom = 0;
    create.style.opacity = 0.4;
    create.style.borderBottom = 0;
    list.style.opacity = 0.4;
    list.style.borderBottom = 0;
    try{
        resetMssg.className = "ocultar";
    }catch{

    }try{
        createMssg.className = "ocultar";
    }catch{

    }try{
        exists.className = "ocultar";
    }catch{

    }
})
list.addEventListener('click',()=>{
    create_user.className = "ocultar";
    reset_pwd.className = "ocultar";
    delete_user.className = "ocultar";
    list_user.className = "mostrar";
    mostrar.className = "ocultar";
    list.style.opacity = 1;
    list.style.borderBottom = "5px solid";
    list.style.borderRadius = "5px";
    reset.style.opacity = 0.4;
    reset.style.borderBottom = 0;
    deleteU.style.opacity = 0.4;
    deleteU.style.borderBottom = 0;
    create.style.opacity = 0.4;
    create.style.borderBottom = 0;
    try{
        deleteMsg.className = "ocultar";
    }catch{

    }try{
        createMssg.className = "ocultar";
    }catch{

    }
    try{
        resetMssg.className = "ocultar";
    }catch{

    }try{
        exists.className = "ocultar";
    }catch{

    }
    
    
})