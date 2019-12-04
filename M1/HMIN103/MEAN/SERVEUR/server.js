"use strict";
var http=require('http');
var assert = require("assert");
var express = require("express");
var app = express();
var MongoClient = require("mongodb").MongoClient;
var url = "mongodb://localhost:27017";
app.use(express.json());
app.use(express.urlencoded({extended:true}));


//petite exemple
/*
var server = http.createServer(function(request, response){
	response.end('Hello World de Node.js');
});
server.listen(8888);
*/

MongoClient.connect(url,{useNewUrlParser: true},(err,client)=>{
	let db= client.db("allovoisins");
	assert.equal(null,err);
	//db.collection("membres").insertOne({"email":"sofiane1000@gmail.fr","mdp":"54+^","nom":"chaher","prenom":"sofiane","role":"member","ville":"montpellier","adresse":"150 rue adrien proby","tel":"+33689512311"});
	


	/*service web permettant de lister le contenue d'une collection
	remplacer le 1er argument de la méthode app.get par le nom 
	de la collection qui nous intéresse*/

	app.get("/membres/:email/:mdp",(req,res) =>{
		console.log("route: membres/"+req.params.email+"/"+req.params.mdp);//gestion d'une route méthode Get
		db.collection("membres").find( {"email": req.params.email,"mdp":req.params.mdp}).toArray((err,documents)=> {
			let json=JSON.stringify({});
			if(documents !== undefined && documents[0]!== undefined)
				json = JSON.stringify(documents[0]);
			console.log(json);
			res.setHeader("Access-Control-Allow-Origin","*");
			res.setHeader("Content-type", "application/json");
			res.end(json);
		});
	});
	

	/************services Web***********************/
	//Ajouter un nouveau membre (inscription)
	/*
	app.get("/membres/:email/:mdp/:nom/:prenom/:role/:ville/:adresse/:tel",(req,res)=>{
		console.log("ok");
		//var insertion="{\"email\":\""+req.params.email+"\",\"mdp\":\""+req.params.mdp+"\",\"nom\":\""+req.params.nom+"\",\"prenom\":\""+req.params.prenom+"\",\"role\":\""+req.params.role+"\",\"ville\":\""+req.params.ville+"\",\"adresse\":\""+req.params.adresse+"\",\"tel\":\""+req.params.tel+"\"}";
		var insertion="{email:\""+req.params.email+"\",mdp:\""+req.params.mdp+"\",nom:\""+req.params.nom+"\",prenom:\""+req.params.prenom+"\",role:\""+req.params.role+"\",ville:\""+req.params.ville+"\",adresse:\""+req.params.adresse+"\",tel:\""+req.params.tel+"\"}";
		db.collection("membres").insertOne(insertion);
		console.log("nouveau membre ajouté !!!");
		res.end(insertion);	
		//tester avec la route suivante :
		//sofiane1000@gmail.fr/54+^/chaher/sofiane/member/montpellier/150 rue adrien proby/+33689512311	
	});
	*/
   
    app.post("/membres/addNewMember", (req, res) => {
		console.log("route sur post : /membres/addNewMember");
		console.log(req.body);
		let json,newMemeber=[];
		for (let prop in req.body) {
				console.log(prop+" : "+req.body[prop]);
				newMemeber.push(req.body[prop]);			
		}
		//res.setHeader("Content-type", "text/raw");
		res.setHeader("Access-Control-Allow-Origin","*");
		res.setHeader("Content-type", "application/json");	
		try {
				db.collection("membres").insertOne(req.body);
				json=JSON.stringify(newMemeber);	
			res.end(json);	    
		}
		catch(e) {
			res.end(JSON.stringify([]));
		}
	});
		
	//Création d'un bien 
	
	app.post("/biens/addNewBien", (req, res) => {
		console.log("route sur post : /biens/addNewBien");
		console.log(req.body);
		for (let prop in req.body) {
				console.log(prop+" : "+req.body[prop]);
		}
		res.setHeader("Content-type", "text/raw");	
		try {
				db.collection("biens").insertOne(req.body);
			res.end("Insertion réussie \n");	    
		}
		catch(e) {
			res.end("Error "+e);
		}
	});
	/*Emprunt d'un bien 
	 * On vérifie si le bien est disponible
	 * Si c'est le cas on le supprime des disponibilités
	 */
	app.post("/disponibilites/empruntBien", (req, res) => {
		console.log("route sur post : /disponibilites/empruntBien");
		res.setHeader("Content-type", "text/raw");
		try{
			db.collection("disponibilites").find(req.body).toArray((err,props)=> {
				for(let prop of props){
					console.log(prop);
				}
			});	
		} //implémenter du côté serveur 
		catch(e){
			res.end("Error : "+e);
		}
		res.setHeader("Content-type", "text/raw");	
		try {
				db.collection("disponibilites").deleteOne(req.body);
			res.end("Emprunt du bien pris en compte ;) \n");	    
		}
		catch(e) {
			res.end("Error "+e);
		}
	});
	//Suppression d'un bien
	app.post("/biens/deleteBien", (req, res) => {
		console.log("route sur post : /biens/deleteBien");
		console.log(req.body);
		db.collection("biens").find(req.body).toArray((err,props)=> {
			for(let prop of props){
				console.log(prop);
			}
		});	
		res.setHeader("Content-type", "text/raw");	
		try {
				db.collection("biens").deleteOne(req.body);
			res.end("Supression réussie \n");	    
		}
		catch(e) {
			res.end("Error "+e);
		}
	});
	//Création d'un service 
	app.post("/services/addNewService", (req, res) => {
		console.log("route sur post : /services/addNewService");
		console.log(req.body);
		for (let prop in req.body) {
				console.log(prop+" : "+req.body[prop]);
		}
		res.setHeader("Content-type", "text/raw");	
		try {
				db.collection("services").insertOne(req.body);
			res.end("Insertion réussie \n");	    
		}
		catch(e) {
			res.end("Error "+e);
		}
	});
	/*Utilisation d'un service
	 * On vérifie si le service est disponible
	 * Si c'est le cas on le supprime des disponibilités
	 */
	app.post("/disponibilites/utilisationService", (req, res) => {
		console.log("route sur post : /disponibilites/utilisationService");
		res.setHeader("Content-type", "text/raw");
		try{
			db.collection("disponibilites").find(req.body).toArray((err,props)=> {
				for(let prop of props){
					console.log(prop);
				}
			});	
		}
		catch(e){
			res.end("Error : "+e);
		}
		res.setHeader("Content-type", "text/raw");	
		try {
				db.collection("disponibilites").deleteOne(req.body);
			res.end("Utilisation du service pris en compte ;) \n");	    
		}
		catch(e) {
			res.end("Error "+e);
		}
	});
	//Suppresion d'un service
	app.post("/services/deleteService", (req, res) => {
		console.log("route sur post : /services/deleteService");
		console.log(req.body);
		db.collection("services").find(req.body).toArray((err,props)=> {
			for(let prop of props){
				console.log(prop);
			}
		});	
		res.setHeader("Content-type", "text/raw");	
		try {
				db.collection("services").deleteOne(req.body);
			res.end("Supression réussie \n");	    
		}
		catch(e) {
			res.end("Error "+e);
		}
	});

	//Calcul des déséquilibres

	/*****Recherches avec différents critères*********/ 

	//Biens

	//Services

	//db.close();
});

app.listen(8888);

//saisir dans la bar d'url : http://localhost:8888




