<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<html>
	<head>
		<meta charset="UTF-8">
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
	</head>
<body>
<?php

try 
{
	$dbh = new PDO('mysql:host=prodpeda-venus;dbname=mterki','mterki','terl_edt');
	$ns = "";
	foreach($dbh->query('SELECT S.numStage,sujet,entreprise,lieu,respENt,respPeda,nom
						FROM etudiant E,stage S
						WHERE E.numStage = S.numStage
						GROUP BY S.numStage,sujet,entreprise,lieu,respENt,respPeda,nom
						;') as $row) 
	{
		if ( isset($row['numStage']))
		{
			if( $row['numStage'] != $ns)
			{
				$ns = $row['numStage'];
				echo '</br>';
				echo $ns,$row['sujet'];
			}
			else 
			{
				print "\t" . $row['nom'];
			
			}
		}
	}

	$dbh = null;
} 

catch (PDOException $e) 
{
	print "Erreur !: " . $e->getMessage() . "<br/>";
	die();
}
?>
</body>
</html>