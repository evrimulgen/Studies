import { Component, OnInit, Input, Output, EventEmitter } from '@angular/core';
import { Router,ActivatedRoute } from '@angular/router';
import { ApplicationService } from '../application.service';
import { FormsModule } from '@angular/forms';
import { Observable } from 'rxjs';
import { first } from 'rxjs/operators';

@Component({
  selector: 'app-application-member',
  templateUrl: './application-member.component.html',
  styleUrls: ['./application-member.component.css']
})

export class ApplicationMemberComponent implements OnInit  {

	iSubscribed: boolean;
	mail :string;
	mdp :string; 
	nom :string;
	prenom :string;
	role :string;
	ville :string;
	adresse :string;
	tel :string;

	constructor(private apply: ApplicationService){}

	ngOnInit(){
		this.iSubscribed=false;
	}

	memberSubscribed(){
		/* traitement*/
		console.log(this.mail);
		console.log(this.mdp);
		console.log(this.nom);
		console.log(this.prenom);
		console.log(this.role);
		console.log(this.ville);
		console.log(this.tel);
		console.log(this.adresse);
		this.apply.addNewMember(this.mail,this.mdp,this.nom,this.prenom,this.role,this.ville,this.tel,this.adresse)
		.pipe(first()).subscribe(
		res=> {console.log(res);},
		error=>{console.log(error);}
		);
		this.iSubscribed=true;
	}

}
