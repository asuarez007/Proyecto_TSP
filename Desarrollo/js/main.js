$(document).ready(function() {
// Plantilla Base de JavaScript

$("#registro").on('submit', function(e){
  if( !validateEmail($("#r4").val())) {
    alert('Dirección de Correo Inválida!');
    e.preventDefault();
  }else{
    $("#registro").submit();
  }
});

$("#checkOut").click(function(){
 alert("Esta Plataforma no Tiene aún el Sistema de Pagos Online. ya que fué diseñada con fines pedagógicos!");
});
       
$("#login").click(function(){
 $(".login").modal('show');
});

$(".login").modal({
 closable: true
});

$('#scroll').click(function(){ 
        $("html, body").animate({ scrollTop: 0 }, 1000); 
        return false; 
});

$('#Buscador').keyup(function(e){
 if(e.keyCode == 13){
   var getval = $("#Buscador").val();
   var result = $.base64.encode(getval);
   $(location).attr('href', '/?page=QnVzY2Fkb3I=&q=' + result);
 }
});

$('#butlogin').click(function(){
 var usuario = $('#login').val();
 var contra = $('#password').val();
 if(!usuario || !contra){
  alert('Es necesario diligenciar el Usuario y la Contraseña');
 }else{
  var data = $.base64.encode($.base64.encode(usuario) + "|" + $.base64.encode(contra));
  $(location).attr('href', '/?page='+ $.base64.encode('login') + '&data=' + data);
 }
});


$('#sendforgot').click(function(){
  var mail = $("#mailforgot").val();
  if(!mail){
   alert("Debes Ingresar una Dirección de Correo Válida!");
  }else{
   $(location).attr('href', '/?page='+ $.base64.encode('enviar correo') + '&data=' + $.base64.encode(mail));
   $("#mailforgot").val("");
  }
});

$('#logout').click(function(){
  $(location).attr('href', '/?page='+ $.base64.encode('logout'));
});

});

function validateEmail($email) {
  var emailReg = /^([\w-\.]+@([\w-]+\.)+[\w-]{2,4})?$/;
  return emailReg.test( $email );
}

function reload(){
  $(location).attr('href', '/');
}

function goBack() {
  window.history.back();
}

function addCart(id_producto,id_user,id_nomape){
  var idu = $.base64.decode(id_user);
  var idp = $.base64.decode(id_producto);
  var idn = $.base64.decode(id_nomape);
  if(idu == 0){
    alert("Debes Iniciar Sesión para poder Agregar productos al Carrito de Compras!");
    $("#cantidad" + idp).val("");
  }else{  
    var cantidad = $("#cantidad" + idp).val();
    if(cantidad > 0){
		alert("Bienvenido " + id_nomape);
      $(location).attr('href', '/?page='+ $.base64.encode('Agregar Producto') + '&data0=' + id_producto + '&data1=' + $.base64.encode(cantidad));
    }else{
      alert("Debes Especificar la Cantidad para este Producto!");
    }
  }
}
