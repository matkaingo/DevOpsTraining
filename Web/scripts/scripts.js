function crearOn(){
    const create_user = document.getElementById('create_user');
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
    
    }
    
    function resetOn(){
        console.log('reset');
        const reset_pwd = document.getElementById('reset_pwd');
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
    }
    function deleteOn(){
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
    }

function mainForm(){
    try{
    const refresh_form = document.getElementById('refreshform');
    if(refresh_form.className == 'formcrear'){
        crearOn();
    }if(refresh_form.className == 'formreset'){
        resetOn();
    }if(refresh_form.className == 'formdelete'){
        deleteOn();
    }
    }catch(e){
        console.log(e);
    }

}


