const create = document.getElementById("create");
const create_user = document.getElementById('create_user');
const reset = document.getElementById("reset");
const reset_pwd = document.getElementById('reset_pwd');
const deleteU = document.getElementById("deleteU");
const delete_user = document.getElementById('delete_user');
const list = document.getElementById("list");
const list_user = document.getElementById('list_user');
const mostrar = document.getElementById("main");

create.addEventListener('click',()=>{
    console.log("Clickeado");
    create_user.className = "mostrar";
    reset_pwd.className = "ocultar";
    delete_user.className = "ocultar";
    list_user.className = "ocultar";
    mostrar.className = "ocultar";
    create.style.opacity = 1;
    create.style.borderBottom = "5px solid";
    reset.style.opacity = 0.4;
    reset.style.borderBottom = 0;
    deleteU.style.opacity = 0.4;
    deleteU.style.borderBottom = 0;
    list.style.opacity = 0.4;
    list.style.borderBottom = 0;
})
reset.addEventListener('click',()=>{
    create_user.className = "ocultar";
    reset_pwd.className = "mostrar";
    delete_user.className = "ocultar";
    list_user.className = "ocultar";
    mostrar.className = "ocultar";
    reset.style.opacity = 1;
    reset.style.borderBottom = "5px solid";
    create.style.opacity = 0.4;
    create.style.borderBottom = 0;
    deleteU.style.opacity = 0.4;
    deleteU.style.borderBottom = 0;
    list.style.opacity = 0.4;
    list.style.borderBottom = 0;
})
deleteU.addEventListener('click',()=>{
    create_user.className = "ocultar";
    reset_pwd.className = "ocultar";
    delete_user.className = "mostrar";
    list_user.className = "ocultar";
    mostrar.className = "ocultar";
    deleteU.style.opacity = 1;
    deleteU.style.borderBottom = "5px solid";
    reset.style.opacity = 0.4;
    reset.style.borderBottom = 0;
    create.style.opacity = 0.4;
    create.style.borderBottom = 0;
    list.style.opacity = 0.4;
    list.style.borderBottom = 0;
})
list.addEventListener('click',()=>{
    create_user.className = "ocultar";
    reset_pwd.className = "ocultar";
    delete_user.className = "ocultar";
    list_user.className = "mostrar";
    mostrar.className = "ocultar";
    list.style.opacity = 1;
    list.style.borderBottom = "5px solid";
    reset.style.opacity = 0.4;
    reset.style.borderBottom = 0;
    deleteU.style.opacity = 0.4;
    deleteU.style.borderBottom = 0;
    create.style.opacity = 0.4;
    create.style.borderBottom = 0;
    
})