/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


var listeChargees = {};

var generationHTML = function(entry)
{
	var html="";
	if(entry['image'])
	{
		html += "<li class='horizontal'>"+entry['nom'];
		html += "<img id='"+entry['lien']+"' src='"+entry['image']+
		 "' width=50 >";
		html += "<ul id='liste_"+entry['lien']+"'></ul></li>";
	} else 
	{
		html += "<li>"+entry['nom']+"</li>"; 
	}
	 return html;
}

var ouvertureFermeture = function()
{
	var id = $(this).attr('id');
	if ( listeChargees.hasOwnProperty("#liste_"+id))
	{
		if(listeChargees["#liste_"+id] == 1)
		{	
			listeChargees["#liste_"+id]=0;
			$("#liste_"+id).hide();
		}else
		{	
			listeChargees["#liste_"+id]=1;	
			$("#liste_"+id).show();
		}
	}else
	{
			$.getJSON(id+".json",function(data){
				$.each(data, function(entryIndex, entry) {
					var html = generationHTML(entry);
					$("#liste_"+id).append(html);

					$(document.body).on('click','#'+entry['lien'],ouvertureFermeture);
					listeChargees["#liste_"+id] = 1;
				});
			});
	}
};

	
	
	

$().ready(function(){
	$("body").append("<ul id='listePrincipale' />"); // ajout de listeP
    console.log("listePrincipale ajoutée");
	$.getJSON('chanteurs.json',function(data){
		$.each(data, function(entryIndex,entry){
			var html = generationHTML(entry);
			$("#listePrincipale").append(html);
			$(document.body).on('click','#'+entry['lien'],ouvertureFermeture);
			console.log("onClick !");
		});
	});
});

