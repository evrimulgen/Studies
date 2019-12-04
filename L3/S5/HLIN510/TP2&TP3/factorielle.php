<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<html>
	<head>
		<title>factorielle</title>
		<meta charset="UTF-8">
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
	</head>
	<body>
		<div style="font-weight: bolder; font-size: 26pt;">Factorielle</div>
		<form method="GET">
			<label>Saissisez un entier</label>
			<input name="integer" type="text">
			<br>
			<input name="fact" type="submit" value="Calculer le factorielle" />
			<br>
			<?php
				
				function factorielle($n)
				{
					if ($n == 0)
					{
						return 1;
					} else if ($n > 0)
					{
						return $n * factorielle($n - 1);
					}
				}
				if ( isset($_GET['integer']) )
				{
					echo factorielle($_GET['integer']);
				}
			?>
		</form>
	</body>
</html>
