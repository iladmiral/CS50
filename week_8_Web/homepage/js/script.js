document.querySelector('#email').onkeyup = function (){
    if (document.querySelector('#email').value === '')
    {
        document.querySelector('#submit').disabled = true;
    }
    else
    {
        document.querySelector('#submit').disabled = false;
    }
}
