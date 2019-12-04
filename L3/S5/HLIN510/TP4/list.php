<?php
	
try 
{
	$dbh = new PDO('mysql:host=prodpeda-venus;dbname=mterki','mterki','terl_edt');
	foreach($dbh->query('SELECT * FROM etudiant;') as $row) 
	{
		print_r($row);
		
	}

	$dbh = null;
} 

catch (PDOException $e) 
{
	print "Erreur !: " . $e->getMessage() . "<br/>";
	die();
}
?>
