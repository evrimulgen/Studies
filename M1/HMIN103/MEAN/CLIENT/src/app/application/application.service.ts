import { Injectable } from '@angular/core';
import { Observable } from 'rxjs';
import { HttpClient,HttpHeaders } from '@angular/common/http';
import { map } from 'rxjs/operators';


@Injectable({
  providedIn: 'root'
})
export class ApplicationService {

	constructor(private http: HttpClient) {}

  	addNewMember(mail : string,mdp: string,nom: string,prenom: string,role: string,ville: string,adresse: string,tel: string): Observable<any>{
		let url= 'http://localhost:8888/membres/addNewMember';
		//let headers = new Headers({ 'Content-Type': 'application/json' });
		let httpOptions = {
 		 	headers: new HttpHeaders({
 		 	'Access-Control-Allow-Origin': '*',	
    		'Content-Type': 'application/json',
    		'Access-Control-Allow-Methods': 'GET, POST'
  			})
		};
		return this.http.post<any>(url,{
		email:mail, mdp:mdp, nom:nom, prenom:prenom, role:role, ville:ville, adresse:adresse, tel:tel
	 },httpOptions);
	}
}
	