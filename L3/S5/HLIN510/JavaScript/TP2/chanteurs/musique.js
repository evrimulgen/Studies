/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



// UTLISER UNIQUEMENT DU JSON 

var connexion;
// déclaration de l’objet qui gérera la connexion avec le serveur
// C’est votre travail d’écrire la fonction suivante :
function creeListesDansLeDOM(noeud, noeud_pere) 
{
	
	
	var liste=document.createElement("ul");
	 
	var element = document.createElement("li");
	element.appendChild(noeud);
	liste.appendChild(element);
	noeud_pere.appendChild(liste);
	for (var num=0; num < noeud.childNodes.length; num++)
	{
		creeListesDansLeDOM(noeud.childNodes.item(num),liste); 
		 
	}
}
// La fonction chargement est une fonction de call-back :
// c’est à dire qu’elle sera exécutée lors de la réception des données

function chargement() 
{
	if (connexion.readyState == 4) 
	{
		// les données ont été intégralement réceptionnées
		contenu=connexion.responseXML;
		// ces données sont accessibles sous forme d’un arbre DOM
			// lancement de l’analyse de l’arbre DOM XML
		for (var num=0; num < contenu.childNodes.length; num++) 
		{
			var noeud_liste = document.createElement("div");
			document.body.appendChild(noeud_liste);
			creeListesDansLeDOM(contenu.childNodes.item(num), noeud_liste);
		}	
	}
}

function chargementXML() 
{
	if (window.XMLHttpRequest) 
	{ // Pour Firefox, Opera et Safari
		connexion = new XMLHttpRequest();
		// création de l’objet gérant la connexion avec le serveur
		if (connexion != 0) 
		{
			connexion.onload = null;
			connexion.open("GET", "musicalTypes.xml", true);
			// préparation de la connexion :
			// une requ^ete HTTP de type GET va ^etre envoyée au serveur
			// pour lui demander de nous renvoyer le document XML
			connexion.onreadystatechange = chargement;
			// c’est la fonction Javascript chargement() qui sera exécutée
			// lors de la réception des données
			connexion.send(null); // envoi de la requete
		}
	}
	else 
	{
		alert("La connexion n a pu etre initiée !"); 
	}
}

// Appel différé du chargement du document XML
setTimeout("chargementXML()", 300);
