<?php
//require '/usr/share/php/libphp-phpmailer/PHPMailerAutoload.php';
//require '/prueba.php';
/*use PHPMailerPHPMailerPHPMailer;
use PHPMailerPHPMailerException;*/
/*require "/PHPMailer/src/Exception.php";
require "/PHPMailer/src/PHPMailer.php";
require "/PHPMailer/src/SMTP.php";*/

require ("SMTP.php");
require("PHPMailer.php");

function SendMail(){
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
 //$mail->AddReplyTo('replyto@correoquesea.com','El de la réplica');
 $mail->AddAddress('asuarezardila@gmail.com', 'Soporte');
 $mail->Subject = 'Esto es un correo de prueba';
 $mail->MsgHTML('<b>Mensaje de Prueba</b>');
 $mail->AltBody = 'Mensaje de Prueba';
 if(!$mail->Send()) {
  echo "Error: " . $mail->ErrorInfo;
 } else {
  echo "Mensaje Enviado!";
 }
}
//include("/PHPMailer-FE_v4.11/lib/class.phpmailer.php");

/*function SendMail(){
 $mail = new PHPMailer();
 $mail->IsSMTP();
 $mail->SMTPDebug  = 0;
 $mail->Host       = 'mail.gmx.com';
 $mail->Port       = 587;
 $mail->SMTPSecure = 'tls';
 $mail->SMTPAuth   = true;
 $mail->Username   = "firebot@gmx.com";
 $mail->Password   = ".kodiak1234.";
 $mail->setFrom('firebot@gmx.com', 'Modrick Joyeria');
 //$mail->AddReplyTo('replyto@correoquesea.com','El de la réplica');
 $mail->AddAddress('ceo@firebot.co', 'Soporte');
 $mail->Subject = 'Esto es un correo de prueba';
 $mail->MsgHTML('<b>Mensaje de Prueba</b>');
 $mail->AltBody = 'Mensaje de Prueba';
 if(!$mail->Send()) {
  echo "Error: " . $mail->ErrorInfo;
 } else {
  echo "Enviado!";
 }
}*/

SendMail();

?>
