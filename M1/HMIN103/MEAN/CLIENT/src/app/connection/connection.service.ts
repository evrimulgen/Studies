import { Injectable } from '@angular/core';
import { Observable } from 'rxjs';
import { HttpClient,HttpHeaders } from '@angular/common/http';
import { map } from 'rxjs/operators';

@Injectable({
  providedIn: 'root'
})

export class ConnectionService {
	
	constructor(private http: HttpClient) {}

	getMemberAccount(params: string): Observable<any>{
		let url= "http://localhost:8888/membres/"+params;
		let observable: Observable<any> = this.http.get(url);
		console.log(observable);
		return observable;
	}
}
