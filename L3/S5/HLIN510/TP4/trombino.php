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
	<form method="POST">
		<b>Sélectionnez une ou plusieurs options</b><br>
			<select name="listopt[]" size="5" multiple="">
				<option value="B">Bio-Informatique</option>
				<option value="C">Chimie</option>
				<option value="L">Langue naturelle</option>
				<option value="S">Syst. d'Info. Géo.</option>
				<option value="W">Web et BD</option>
			</select>
		<div><b>Puis choisissez l'ordre d'affichage</b></div>
			<select name="ordre">
			<option  value='nom'>par nom et prénom
			<option  value='option'>par option
			<option selected value='groupe'>par groupe
			<option  value='statut'>par statut (FI/FP)
			</select>
		<div>Enfin validez !</div>
			<input type="SUBMIT" name="valider" value="valider">
		
		<?php
	
			
			try{
				$dbh = new PDO('mysql:host=prodpeda-venus;dbname=mterki','mterki','terl_edt');
			}
			catch (PDOException $E){
				echo "impossible de se connecter";
			}
			
			if( ! empty($_POST['listopt']))
			{
				
				$lo="";
					foreach($_POST['listopt'] as $option)
					{	$lo=$lo."'".$option."',";
					}
					 $lo=substr($lo,0,-1);
					 $sql="SELECT *
						FROM etudiant
						WHERE
							opt  IN (".$lo.")

						GROUP BY ".$_POST['ordre'];
					 //var_dump($sql);
					$res=$dbh->query($sql);
			
			foreach($res as $row)
			{
				echo '<div>'.$row['nom'].";".$row['prenom'].";".$row['statut'].";".$row['groupe'].";".$row['opt'].'</div>';
			}
			}
			
		?>
		
			
			
			
	</form>

</body>
</html>