<?php

session_start();

require("tsp/db.inc");

class tspAPI {


public function getCSS(){
$css = <<<EOF
<link href="//maxcdn.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" rel="stylesheet" id="bootstrap-css">
<link href="https://maxcdn.bootstrapcdn.com/font-awesome/4.7.0/css/font-awesome.min.css" rel="stylesheet" integrity="sha384-wvfXpqpZZVQGK6TAh5PVlGOfQNHSoD2xbE+QkPxCAFlNEevoEH3Sl0sibVcOQVnN" crossorigin="anonymous">
<link rel="stylesheet" href="https://unpkg.com/leaflet@1.5.1/dist/leaflet.css" integrity="sha512-xwE/Az9zrjBIphAcBb3F6JVqxf46+CDLwfLMHloNu6KEQCAWi6HcDUbeOfBIptF7tcCzusKFjFw2yuvEpDL9wQ==" crossorigin=""/>
<link rel="stylesheet" type="text/css" href="/css/main.css" >
EOF;
return $css;
}

/*public function SendMail($correo, $nombres, $usuario, $clave){
 //require '/usr/share/php/libphp-phpmailer/PHPMailerAutoload.php';
 require '/prueba.php';
 $mail = new PHPMailer();
 $mail->IsSMTP();
 $mail->SMTPDebug  = 0;
 $mail->Host       = 'mail.gmx.com';
 $mail->Port       = 587;
 $mail->SMTPSecure = 'tls';
 $mail->SMTPAuth   = true;
 $mail->Username   = "firebot@gmx.com";
 $mail->Password   = ".kodiak1234.";
 $mail->SetFrom('firebot@gmx.com', 'Modrick Joyeria');
 $mail->AddAddress($correo, $nombres);
 $mail->Subject = 'Modrick Joyeria Clave de Acceso';
 $mail->MsgHTML("<b>Hola $nombres</b><hr>Las Credenciales de Acceso a Nuestro Sistema son: <lu><li>Usuario: $usuario</li><li>Clave: $clave</li></lu>");
 $mail->AltBody = "Hola $nombres, Sus Credenciales de Acceso a Nuestro Sistema son: 1- Usuario $usuario, 2- Clave: $clave";
 if(!$mail->Send()) {
  echo "Error: " . $mail->ErrorInfo;
 } else {
echo <<<EOF
<div class="card col-md-12 border-0 mb-2"><button type="button" class="btn btn-success h2 p-3 text-uppercase font-weight-bold">
<h1><i class="fa fa-send fa-lg"></i></h1>
Mensaje enviado a tu dirección de correo $correo
</div>
EOF;
 }
}*/

public function SendMail($correo, $nombres, $usuario, $clave){
 //require '/usr/share/php/libphp-phpmailer/PHPMailerAutoload.php';
 require "/prueba.php";
	
 $mail = new PHPMailer();
 $mail->IsSMTP();
 $mail->SMTPDebug  = 0;
 $mail->Host       = 'smtp.live.com';
 $mail->Port       = 587;
 $mail->SMTPSecure = 'tls';
 $mail->SMTPAuth   = true;
 $mail->Username   = "asuarezardila@outlook.com";
 $mail->Password   = "nacional1";
 $mail->SetFrom('asuarezardila@outlook.com', 'Modrick Joyeria');
 $mail->AddAddress($correo, $nombres);
 $mail->Subject = 'Modrick Joyeria Clave de Acceso';
 $mail->MsgHTML("<b>Hola $nombres</b><hr>Las Credenciales de Acceso a Nuestro Sistema son: <lu><li>Usuario: $usuario</li><li>Clave: $clave</li></lu>");
 $mail->AltBody = "Hola $nombres, Sus Credenciales de Acceso a Nuestro Sistema son: 1- Usuario $usuario, 2- Clave: $clave";
 if(!$mail->Send()) {
  echo "Error: " . $mail->ErrorInfo;
 } else {
echo <<<EOF
<div class="card col-md-12 border-0 mb-2"><button type="button" class="btn btn-success h2 p-3 text-uppercase font-weight-bold">
<h1><i class="fa fa-send fa-lg"></i></h1>
Mensaje enviado a tu dirección de correo $correo
</div>
EOF;
 }
}

public function forgotPasswd($email){
 global $db;
 $sql = "SELECT correo, nombres, apellidos, usuario, clave FROM usuarios WHERE correo='".$email."'";
 $sth = $db->query($sql);
 $row = $sth->fetch_row();
 if($row[0]){
 $this->SendMail($row[0], $row[1].' '.$row[2], $row[3], $row[4]);
 }else{
echo <<< EOF
<div class="card col-md-12 border-0 mb-2"><button type="button" class="btn btn-danger h2 p-3 text-uppercase font-weight-bold">
<h1><i class="fa fa-envelope fa-lg"></i></h1>
Esta dirección de Correo Electrónico $email no Existe en nuestro sistema!
<br>
Intenta Nuevamente
</div>
EOF;
 }
}




public function getJS(){
$js = <<<EOF
<script src="//cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js"></script>
<script src="//maxcdn.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js"></script>
<script src="https://unpkg.com/leaflet@1.5.1/dist/leaflet.js" integrity="sha512-GffPMF3RvMeYyc1LWMHtK8EbPv0iNZ8/oTtHPx9/cc2ILxQ+u905qIwdpULaqDkyBKgOaB57QTMg7ztg8Jm2Og==" crossorigin=""></script>
<script src="/js/jquery.base64.js"></script>
<script src="/js/main.js"></script>
EOF;
return $js;
}


public function newProduct($id_producto,$producto,$descripcion,$cantidad,$precio,$image){
$lcantidad = "cantidad".$id_producto;
$cidp = base64_encode($id_producto);
if($_SESSION["id_usuario"]){
$idUser = base64_encode($_SESSION["id_usuario"]);
$idNom = base64_encode($_SESSION["nombres"]);
}else{
$idUser = base64_encode(0);
}
$base = <<<EOF
<div class="col-12 col-md-6 col-lg-4">
                    <div class="card">
                        $image
                        <div class="card-body">
                            <h4 class="card-title">$producto</h4>
                            <p class="card-text">$descripcion</p>
                            <div class="row">
                                <div class="col-12">
                                    <p class="btn btn-danger btn-block">Precio: $ $precio</p>
                                </div>
                                <div class="col-12">
                                    <input type="text" class="form-control" id="$lcantidad" value="" placeholder="Cantidad">
                                </div>
                                <div class="col-12">
                                    <a href="javascript:addCart('$cidp', '$idUser', '$idNom');" class="btn btn-success btn-block" id="addCart">A&ntilde;adir al Carrito</a>
                                </div>
                            </div>
                        </div>
                    </div>
                </div>
EOF;
return $base;
}

public function aboutus(){
$asuarez = "img/suarez.jpg";
$fernando = "img/fernando.jpeg";

$priv = "<div clas='container'><div class='row'>";
$imagea = "<div class=\"col-lg-5 d-flex align-items-stretch\"><div class='card'><img src='".$asuarez."' class='card-img-top'><div class='card-body'><div class='card-title text-center'><b>Arnoldo Suárez Ardila</b><br>C&oacute;digo 1711025679</div></div></div></div>";
$imagef = "<div class=\"col-lg-6 d-flex align-items-stretch\"><div class=\"card\"><img src='".$fernando."' class='card-img-top'><div class='card-body'><div class='card-title text-center'><b>Fernando Rodríguez Caro</b><br>C&oacute;digo 1311070271</div></div></div></div>";
$dest = "<div class='p-3 text-justify'><br><br><b>Estudiantes de Ingenier&iacute;a de Software, Asignatura: TSP.</b><br><br>En combinaci&oacute;n con el Personal Software Process (PSP), el llamado Team Software Process (TSP) proporciona un marco de trabajo de procesos definidos que est&aacute; dise&ntilde;ado para ayudarle a equipos de gerentes e ingenieros a organizar y producir proyectos de software de gran escala, que tengan tama&ntilde;os mayores a varios miles de l&iacute;neas de c&oacute;digo. El objetivo del TSP es mejorar los niveles de calidad y productividad de un proyecto de desarrollo de software de un equipo, con el fin de ayudarlos a alcanzar los acuerdos de costos y tiempos en dicho desarrollo.</div>";
print($imagea . "&nbsp;" . $imagef . "&nbsp;" . $dest . "</div></div>");
}

public function fullProduct($id_producto,$producto,$descripcion,$cantidad,$precio,$image,$plu){
$lcantidad = "cantidad".$id_producto;
$cidp = base64_encode($id_producto);
if($_SESSION["id_usuario"]){
$idUser = base64_encode($_SESSION["id_usuario"]);
}else{
$idUser = base64_encode(0);
}

$base = <<<EOF
<div class="col-12 col-md-12 col-lg-12">
                    <div class="card">
                      <div class="row">
                       <div class="col">
                        $image
                       </div>
                       <div class="col">
                        <div class="card-body">
                            <h4 class="card-title">$producto</h4>
                            <p class="card-text">$descripcion</p>
                            <p class="card-text">C&oacute;digo PLU: $plu</p>
                            <p class="card-text">Disponibilidad en Inventario: $cantidad</p>
                            <div class="row">
                                <div class="col-12">
                                    <p class="btn btn-danger btn-block">Precio: $ $precio</p>
                                </div>
                                <div class="col-12">
                                    <input type="text" name="cantidad" id="$lcantidad" class="form-control" value="" placeholder="Cantidad">
                                </div>
                                <div class="col-12">
                                    <a href="javascript:addCart('$cidp', '$idUser', '$idNom');" id="addCart" class="btn btn-success btn-block">A&ntilde;adir al Carrito</a>
                                </div>
                            </div>
                        </div>
                       </div>
                      </div>
                    </div>
                </div>
EOF;
return $base;
}


public function setBegin($lang){
$css = $this->getCSS();
$js = $this->getJS();
$base = <<<EOF
<!DOCTYPE html>
<html lang="$lang" xml:lang="$lang">
<head>
<title>Modrick Joyer&iacute;a</title>
	<meta http-equiv="Expires" content="0">
	<meta http-equiv="Last-Modified" content="0">
	<meta http-equiv="Cache-Control" content="no-cache, mustrevalidate">
	<meta http-equiv="Pragma" content="no-cache">
	<meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="">
    <meta name="author" content="">
$css
$js
</head>
<body>
EOF;
return $base;
}


public function randProducts($num){
$detprod = base64_encode("producto");
global $db;
$sql = "SELECT id_producto,nombre_producto,descripcion,cantidad,precio_venta,imagen FROM inventario ORDER BY RAND() LIMIT ".$num;
$sth = $db->query($sql);
while ($fila = $sth->fetch_row()) {
        $id_producto = $fila[0];
        $producto = $fila[1];
        $descripcion = $fila[2];
        $cantidad = $fila[3];
        $precio = number_format($fila[4]);
        $image = '<a href="/?page='.$detprod.'&q='.base64_encode($fila[0]).'"><img class="card-img-top" width="100px" src="data:image/jpeg;base64,'.base64_encode( $fila[5] ).'"/></a>';
        print($this->newProduct($id_producto,$producto,$descripcion,$cantidad,$precio,$image));
}
}

public function searchProduct($prod){
$detprod = base64_encode("producto");
global $db;
$sql = "SELECT id_producto,nombre_producto,descripcion,cantidad,precio_venta,imagen FROM inventario WHERE descripcion like '%".$prod."%'";
$sth = $db->query($sql);
$count = $sth->num_rows;
if($count > 0){
 while ($fila = $sth->fetch_row()) {
        $id_producto = $fila[0];
        $producto = $fila[1];
        $descripcion = $fila[2];
        $cantidad = $fila[3];
        $precio = number_format($fila[4]);
        $image = '<a href="/?page='.$detprod.'&q='.base64_encode($fila[0]).'"><img class="card-img-top" width="100px" src="data:image/jpeg;base64,'.base64_encode( $fila[5] ).'"/></a>';
        print($this->newProduct($id_producto,$producto,$descripcion,$cantidad,$precio,$image));
 }
}else{
print("<div class='card-body'><div class='card-text h1'>Sin Resultados!</div></div>");
}
}


public function detProduct($num){
global $db;
$sql = "SELECT id_producto,nombre_producto,descripcion,cantidad,precio_venta,imagen,plu FROM inventario WHERE id_producto=".$num;
$sth = $db->query($sql);
while ($fila = $sth->fetch_row()) {
        $id_producto = $fila[0];
        $producto = $fila[1];
        $descripcion = $fila[2];
        $cantidad = $fila[3];
        $precio = number_format($fila[4]);
        $plu = $fila[6];
        $image = '<img class="card-img-top" width="100px" src="data:image/jpeg;base64,'.base64_encode( $fila[5] ).'"/>';
        print($this->fullProduct($id_producto,$producto,$descripcion,$cantidad,$precio,$image,$plu));
}
}


public function catProducts($num){
$detprod = base64_encode("producto");
global $db;
$sql = "SELECT id_producto,nombre_producto,descripcion,cantidad,precio_venta,imagen FROM inventario WHERE categoria=".$num;
$sth = $db->query($sql);
while ($fila = $sth->fetch_row()) {
        $id_producto = $fila[0];
        $producto = $fila[1];
        $descripcion = $fila[2];
        $cantidad = $fila[3];
        $precio = number_format($fila[4]);
        $image = '<a href="/?page='.$detprod.'&q='.base64_encode($fila[0]).'"><img class="card-img-top" width="100px" src="data:image/jpeg;base64,'.base64_encode( $fila[5] ).'"/></a>';
        print($this->newProduct($id_producto,$producto,$descripcion,$cantidad,$precio,$image));
}
}

public function login($user, $pass){
 global $db;
 $sql = "SELECT id_usuario, nombres, apellidos, direccion, telefono FROM usuarios WHERE usuario='".$user."' AND clave='".$pass."'";
 $sth = $db->query($sql);
 $row = $sth->fetch_row();
 if(strlen($row[0]) > 0){
 $_SESSION['id_usuario'] = $row[0];
 $_SESSION['usuario'] = $row[1];
 $_SESSION['apellidos'] = $row[2];
 $_SESSION['direccion'] = $row[3];
 $_SESSION['telefono'] = $row[4];
 echo "<script>reload();</script>";
 }else{
echo <<< EOF
<div class="card col-md-12 border-0 mb-2"><button type="button" class="btn btn-danger h2 p-3 text-uppercase font-weight-bold">
<h1><i class="fa fa-lock fa-lg"></i></h1>
Usuario y Contrase&ntilde;a Incorrecta!
<br>
Intenta Nuevamente
</div>
EOF;
 }
}



public function destProduct(){
$detprod = base64_encode("producto");
global $db;
$sql = "SELECT id_producto,nombre_producto,descripcion,cantidad,precio_venta,imagen FROM inventario ORDER BY RAND() LIMIT 1";
$sth = $db->query($sql);
$fila = $sth->fetch_row();
$producto = $fila[1];
$descripcion = $fila[2];
$cantidad = $fila[3];
$precio = $fila[4];
$image = '<a href="/?page='.$detprod.'&q='.base64_encode($fila[0]).'"><img class="card-img-top" width="100px" src="data:image/jpeg;base64,'.base64_encode( $fila[5] ).'"/></a>';
$base = <<<EOF
                    <div class="card">
                        $image
                        <div class="card-body">
                            <h4 class="card-title">$producto</h4>
                            <p class="card-text">$descripcion</p>
                        </div>
                    </div>
EOF;
return $base;
}

public function forgot(){
echo <<<EOF
<div class="col-12 col-md-12 col-lg-12">
Ingrese la Direcci&oacute;n de Correo Electr&oacute;nico con la que se Registr&oacute; y le enivaremos un correo con informaci&oacute;n de Ingreso.
<br><br>
<input type="text" class="fadeIn w-50" id="mailforgot" placeholder="CORREO ELECTR&Oacute;NICO">
<input type="submit" class="fadeIn" value="ENVIAR" id="sendforgot">
</div>
EOF;
}

public function contactForm(){
$formcnt = base64_encode('contactFormulario');
echo <<<EOF
<div class="col-12 col-md-12 col-lg-12">
<hr>
Direcci&oacute;n: Estamos ubicados en la Calle 13 # 128A - 24, localidad Fontibón.
<br>
Tel&eacute;fonos: +57(1)2223333, 57(1)2010101
<br>
Celular: +57-3502111111
</div>
EOF;
}



public function newuser(){
$formadd = base64_encode('registro de usuario');
echo <<<EOF
<div class="col-12 col-md-12 col-lg-12">
Ingrese toda la información requerida
<br><br>
<form action="/?page=$formadd" method="post" id="registro">
<input type="text" class="fadeIn" name="r1" id="r1" placeholder="NOMBRES" required>
<input type="text" class="fadeIn" name="r2" id="r2" placeholder="APELLIDOS" required>
<input type="text" class="fadeIn" name="r3" id="r3" placeholder="IDENTIFICACI&Oacute;N" required>
<input type="text" class="fadeIn" name="r4" id="r4" placeholder="CORREO ELECTR&Oacute;NICO" aria-describedby="emailHelp" required>
<input type="text" class="fadeIn" name="r5" id="r5" placeholder="DIRECCI&Oacute;N" required>
<input type="text" class="fadeIn" name="r6" id="r6" placeholder="TEL&Eacute;FONO" required>
<input type="text" class="fadeIn" name="r7" id="r7" placeholder="CIUDAD" required>
<input type="text" class="fadeIn" name="r8" id="r8" placeholder="DEPARTAMENTO" required>
<hr>
Datos de Ingreso al Sistema
<hr>
<input type="text" class="fadeIn" name="r9" id="r9" placeholder="USUARIO" required>
<input type="password" class="fadeIn" name="r10" id="r10" placeholder="CONTRASE&Ntilde;A" required>

<input type="submit" class="fadeIn" value="ENVIAR" id="sendform">
</form>
</div>
EOF;
}


public function addUser($r1,$r2,$r3,$r4,$r5,$r6,$r7,$r8,$r9,$r10){
 global $db;
 $sql = "SELECT count(correo) FROM usuarios WHERE correo='".$r4."'";
 $sth = $db->query($sql);
 $row = $sth->fetch_row();
 if($row[0] == 1){
  echo "<div class=\"card col-md-12 border-0 mb-2\"><button type=\"button\" class=\"btn btn-danger h2 p-3 text-uppercase font-weight-bold\"><h1><i class=\"fa fa-exclamation-triangle\" aria-hidden=\"true\"></i></h1>Usuario ya Existe en Nuestro Sistema</button></div>";
 }else{
  $sqla = "INSERT INTO usuarios (nombres,apellidos,identificacion,correo,direccion,telefono,ciudad,departamento,usuario,clave) VALUES('$r1','$r2','$r3','$r4','$r5','$r6','$r7','$r8','$r9','$r10')";
  if ($db->query($sqla) === TRUE) {
	echo "<div class=\"card col-md-12 border-0 mb-2\"><button type=\"button\" class=\"btn btn-success h2 p-3 text-uppercase font-weight-bold\">Bienvenid@ $r1 $r2 ,ya perteneces a la Familia Modrick Joyer&iacute;a!!</button></div>";
  } else {
    echo "Error: " . $sqla . "<br>" . $db->error;
  }
  
 }
}


public function shoppingCart(){
 global $db;
 $total = 0;
 echo "<button type=\"button\" class=\"btn btn-warning col-md-12 h2 p-3 text-uppercase font-weight-bold\">Carrito de Compras Modrick Joyer&iacute;a</button>";
 if($_SESSION['id_usuario']){
  $sql = "SELECT count(*) FROM compras WHERE Id_usuario=".trim($_SESSION['id_usuario']);
  $sth = $db->query($sql);
  $row = $sth->fetch_row();
  if($row[0] == 0){
   echo "<div class='col-md-12'><h1>Hola: ".$_SESSION['usuario']." ".$_SESSION['apellidos']."</h1><hr>En este momento, no haz realizado ning&uacute;n movimiento de inventario hacia el carrito de compras!<br><br>Te Invitamos a Conocer Nuestros Productos y Llevartelos a tu Casa!<br><hr><b><h3>Modrick Joyer&iacute;a</h3></b></div>";
  }else{
   $sqla = "SELECT b.Id_compra, a.nombre_producto, b.cantidad, a.precio_venta, b.precio FROM inventario as a, compras as b WHERE b.Id_usuario=".$_SESSION['id_usuario']." AND a.Id_producto = b.Id_producto";
   $stha = $db->query($sqla);
   echo "<table class='table table-bordered table-striped'><thead class='thead-dark'><tr><th scope='col'>Producto</th><th scope='col'>Cantidad</th><th scope='col'>V/U</th><th scope='col'>V/T</th><th></th></tr></thead>";
   $removepage = base64_encode("Eliminar Producto");
   while($rowa = $stha->fetch_row()){
    $total = $total + $rowa[4];
    echo "<tr><th scope='row'>".$rowa[1]."</th><td>".$rowa[2]."</td><td>$".number_format($rowa[3])."</td><td>$".number_format($rowa[4])."</td><td><a href='/?page=".$removepage."&data=".base64_encode($rowa[0])."' title='Eliminar Producto'><li class='fa fa-trash text-danger' aria-hidden='true'></li></a></td></tr>";
   }
   echo "<tr><th scope='row' colspan='3' class='table-dark'>Valor Total de su Compra</th><td>$".number_format($total)."</td><td class='table-dark'></td></tr>";
   echo "</table>";
   echo "<button type=\"button\" class=\"btn btn-info col-md-12 h2 p-3 text-uppercase font-weight-bold\" id=\"checkOut\">Confirmar su Compra</button>";
  }
 }else{
echo <<<EOF
<div class="col-md-12 bg-success rounded p-4 text-light font-weight-bold h2">No existen Items en el Carrito de Compras</div>
EOF;
 }
}

public function itemsCart(){
 global $db;
 if($_SESSION['id_usuario']){
  $id_user = $_SESSION['id_usuario'];
  $sql = "SELECT count(*) FROM compras WHERE Id_usuario=".$id_user;
  $sth = $db->query($sql);
  $row = $sth->fetch_row();
  return $row[0];
  $db->close();
 }else{
  return 0;
 }
}

public function removeItemCart($id_item){
 global $db;
 $sql = "DELETE FROM compras WHERE Id_compra=".intval($id_item);
 $sth = $db->query($sql);
 $db->close();
 echo <<<EOF
<script>
location.href = "/?page=Y2Fycml0byBkZSBjb21wcmFz";
</script>
EOF;
}

public function addItemCart($id_usuario,$id_producto,$cantidad){
 global $db;
 $sql = "INSERT INTO compras (Id_usuario,Id_producto,cantidad) VALUES (".intval($id_usuario).",".intval($id_producto).",".intval($cantidad).")";
 if ($db->query($sql) === TRUE) {
 echo <<<EOF
<script>
location.href = "/?page=Y2Fycml0byBkZSBjb21wcmFz";
</script>
EOF;
 }else{
  echo "Error: " . $sql . "<br>" . $db->error;$db-error;
 }
 $db->close();
}


public function setPages($lang, $page){
 if ($page == base64_encode("quienes somos")){
  echo "<button type=\"button\" class=\"btn btn-warning col-md-12 h2 p-3 text-uppercase font-weight-bold\">Quienes Somos?</button>";
  $this->aboutus();
 }elseif ($page == base64_encode("Agregar Producto")){
  $idp = base64_decode($_REQUEST["data0"]);
  $cant = base64_decode($_REQUEST["data1"]);
  $this->addItemCart($_SESSION["id_usuario"],$idp,$cant);
 }elseif ($page == base64_encode("Eliminar Producto")){
  $q = $_REQUEST["data"];
  $q = base64_decode($q);
  $this->removeItemCart($q);
 }elseif ($page == base64_encode("login")){
  $q = $_REQUEST["data"];
  $data = explode("|", base64_decode($q));
  $this->login(base64_decode($data[0]), base64_decode($data[1]));
 }elseif ($page == base64_encode("logout")){
  session_destroy();
  echo "<script>reload();</script>";
 }elseif ($page == base64_encode("contactanos")){
  echo "<button type=\"button\" class=\"btn btn-info col-md-12 h2 p-3 text-uppercase font-weight-bold\">Cont&aacute;ctanos</button>";
  echo <<<EOF
<div id="mapid" style="width: 100%; height: 400px;"></div>
<script>

	var mymap = L.map('mapid').setView([4.68, -74.09], 13);

	L.tileLayer('https://api.tiles.mapbox.com/v4/{id}/{z}/{x}/{y}.png?access_token=pk.eyJ1IjoibWFwYm94IiwiYSI6ImNpejY4NXVycTA2emYycXBndHRqcmZ3N3gifQ.rJcFIG214AriISLbB6B5aw', {
		maxZoom: 18,
		attribution: '<a href="https://www.firebot.co/">FireBot Colombia</a>',
		id: 'mapbox.streets'
	}).addTo(mymap);

	L.marker([4.68, -74.17]).addTo(mymap)
		.bindPopup("<b>Modrick Joyería</b><br />Nuestra Ubicación.").openPopup();

</script>
EOF;
  $this->contactForm();
 }elseif ($page == base64_encode("registro de usuario")){
  $r1 = $_POST['r1'];
  $r2 = $_POST['r2'];
  $r3 = $_POST['r3'];
  $r4 = $_POST['r4'];
  $r5 = $_POST['r5'];
  $r6 = $_POST['r6'];
  $r7 = $_POST['r7'];
  $r8 = $_POST['r8'];
  $r9 = $_POST['r9'];
  $r10 = $_POST['r10'];
  $this->addUser($r1,$r2,$r3,$r4,$r5,$r6,$r7,$r8,$r9,$r10);
 }elseif ($page == base64_encode("enviar correo")){
  $q = $_REQUEST["data"];
  $this->forgotPasswd(base64_decode($q)); 
 }elseif ($page == base64_encode("carrito de compras")){
  $this->shoppingCart();
 }elseif ($page == base64_encode("1")){
  echo "<div class=\"card col-md-12 border-0 mb-2\"><button type=\"button\" class=\"btn btn-warning h2 p-3 text-uppercase font-weight-bold\">Categor&iacute;a Collares</button></div>";
  $this->catProducts(1);
 }elseif ($page == base64_encode("2")){
  echo "<div class=\"card col-md-12 border-0 mb-2\"><button type=\"button\" class=\"btn btn-warning h2 p-3 text-uppercase font-weight-bold\">Categor&iacute;a Pendientes</button></div>";
  $this->catProducts(2);
 }elseif ($page == base64_encode("3")){
  echo "<div class=\"card col-md-12 border-0 mb-2\"><button type=\"button\" class=\"btn btn-warning h2 p-3 text-uppercase font-weight-bold\">Categor&iacute;a Relojer&iacute;a</button></div>";
  $this->catProducts(3);
 }elseif ($page == base64_encode("4")){
  echo "<div class=\"card col-md-12 border-0 mb-2\"><button type=\"button\" class=\"btn btn-warning h2 p-3 text-uppercase font-weight-bold\">Categor&iacute;a Brazaletes</button></div>";
  $this->catProducts(4);
 }elseif ($page == base64_encode("5")){
  echo "<div class=\"card col-md-12 border-0 mb-2\"><button type=\"button\" class=\"btn btn-warning h2 p-3 text-uppercase font-weight-bold\">Categor&iacute;a Accesorios</button></div>";
  $this->catProducts(5);
 }elseif ($page == base64_encode("forgot")){
  echo "<div class=\"card col-md-12 border-0 mb-2\"><button type=\"button\" class=\"btn btn-info h2 p-3 text-uppercase font-weight-bold\">Recuperar Contrase&ntilde;a</button></div>";
  $this->forgot();
 }elseif ($page == base64_encode("register")){
  echo "<div class=\"card col-md-12 border-0 mb-2\"><button type=\"button\" class=\"btn btn-info h2 p-3 text-uppercase font-weight-bold\">Registro de Usuario</button></div>";
  $this->newuser();
 }elseif ($page == base64_encode("producto")){
  $q = $_REQUEST["q"];
  echo "<div class=\"card col-md-12 border-0 mb-2\"><button type=\"button\" class=\"btn btn-warning h2 p-3 text-uppercase font-weight-bold\">Detalles del Producto</button></div>";
  $this->detProduct(base64_decode($q));
 }elseif ($page == base64_encode("Buscador")){
  $q = $_REQUEST["q"];
  echo "<div class=\"card col-md-12 border-0 mb-2\"><button type=\"button\" class=\"btn btn-warning h2 p-3 text-uppercase font-weight-bold\">Resultado de la B&uacute;squeda: " . base64_decode($q)."</button></div>";
  $this->searchProduct(base64_decode($q));
 }else{
  echo "<div class=\"card col-md-12 border-0 mb-2\"><button type=\"button\" class=\"btn btn-warning h2 p-3 text-uppercase font-weight-bold\">Nuestros Productos</button></div>";
  $this->randProducts(9);
 }
}

public function setEnd($lang){
$forgot = base64_encode("forgot");
$register = base64_encode("register");
$base = <<<EOF
            </div>
        </div>

    </div>
</div>

<!-- Footer -->
<footer class="text-light">
    <div class="container">
        <div class="row">
            <div class="col-12 copyright mt-3">
                <p class="float-left">
                    <a href="javascript:void(0);" id="scroll">Volver Arriba</a>
                </p>
                <p class="text-right text-muted">Creado con <i class="fa fa-heart"></i> para <i>TSP [Polit&eacute;cnico Gran Colombiano]</i> | <span>v. 1.0</span></p>
            </div>
        </div>
    </div>
</footer>
<div class="modal fade bg-blue" id="myModal">
 <div class="modal-dialog modal-dialog-centered">
  <div class="modal-content text-center" id="formContent">
   <div class="modal-header">
    <h4 class="modal-title font-weight-bold">Ingreso a Modrick Joyer&iacute;a</h4>
    <button type="button" class="close" data-dismiss="modal">&times;</button>
   </div>
   <div class="modal-body">
    <input type="text" id="login" class="fadeIn" name="login" placeholder="USUARIO">
    <input type="password" id="password" class="fadeIn" name="login" placeholder="CONTRASE&Ntilde;A">
    <input type="submit" class="fadeIn" value="Ingresar" id="butlogin">        
   </div>
   <div class="modal-footer">
    <a href="/?page=$register">Registrarse</a> | <a href="/?page=$forgot">Olvid&eacute; la Contrase&ntilde;a</a>
   </div>
  </div>
 </div>
</div>
\n</body>
</html>
EOF;
return $base;
}

public function makePageAll(){
$aboutme = base64_encode("quienes somos");
$login = base64_encode("login");
$cart = base64_encode("carrito de compras");
$contacto = base64_encode("contactanos");
$cat1 = base64_encode("1");
$cat2 = base64_encode("2");
$cat3 = base64_encode("3");
$cat4 = base64_encode("4");
$cat5 = base64_encode("5");

if($_SESSION['usuario']){
 $butt0 = '<button type="button" class="btn btn-sm btn-warning" id="logout">Cerrar Sesi&oacute;n</button>';
}else{
 $butt0 = '<button type="button" class="btn btn-sm btn-primary" data-toggle="modal" data-target="#myModal">Iniciar Sesi&oacute;n</button>';
}
$itemscart = $this->itemsCart();
$base = <<<EOF
<nav class="navbar navbar-expand-md navbar-dark bg-dark">
    <div class="container">
        <a class="navbar-brand font-weight-bold text-uppercase" href="/">Modrick Joyer&iacute;a</a>
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#tsp1" aria-controls="tsp1" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse justify-content-end" id="tsp1">
            <ul class="navbar-nav m-auto">
                <li class="nav-item">
                    <a class="nav-link font-weight-bold" href="/">Inicio</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link font-weight-bold" href="/?page=$aboutme">Quienes Somos?</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link font-weight-bold" href="/?page=$contacto">Cont&aacute;ctanos</a>
                </li>
            </ul>
<div class="form-inline md-form form-sm mt-0">
<div>
  <input class="form-control form-control-sm ml-3 w-50 border-0" type="text" placeholder="Buscador" aria-label="Search" id="Buscador">
  <i class="fa fa-search text-light" aria-hidden="true"></i>
</div>
                <div class="ml-0 mt-0">
                <a class="btn btn-success btn-sm ml-3" href="/?page=$cart">
                    <i class="fa fa-shopping-cart"></i> Compras
                    <span class="badge badge-light">$itemscart</span>
                </a>
                <span>&nbsp;</span>
                 $butt0
                </div>
          </div>
</div>
        </div>
    </div>
</nav>
<section class="p-5 text-center wallpaper">
    <div class="container">
        <div class="col-md-12 justify-content-center bg-dark font-weight-bold text-light p-2 border border-0 rounded text-uppercase h2" style="opacity: 0.5; filter: alpha(opacity=50);">Cuando la alta joyería esta al alcance de tus manos!</div>
    </div>
</section>
<div class="container mt-3">
    <div class="row">
        <div class="col-12 col-sm-3">
            <div class="card bg-light mb-3">
                <div class="card-header bg-primary text-white text-uppercase"><i class="fa fa-list"></i> Categor&iacute;as</div>
                <ul class="list-group category_block">
                    <li class="list-group-item"><a href="../?page=$cat1">Collares</a></li>
                    <li class="list-group-item"><a href="../?page=$cat2">Pendientes</a></li>
                    <li class="list-group-item"><a href="../?page=$cat3">Relojer&iacute;a</a></li>
                    <li class="list-group-item"><a href="../?page=$cat4">Brazaletes</a></li>
                    <li class="list-group-item"><a href="../?page=$cat5">Accesorios</a></li>
                </ul>
            </div>
            <div class="card bg-light mb-3">
                <div class="card-header bg-success text-white text-uppercase">Producto Destacado</div>
EOF;
$destp = $this->destProduct();
$base = $base . <<<EOF
           $destp
        </div> 
        </div>
        <div class="col">
            <div class="row">
EOF;
return $base;
}

}
