import { Component, OnInit } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { ConnectionService } from '../connection.service';
import { Observable } from 'rxjs';
import { Router,ActivatedRoute } from '@angular/router';

@Component({
  selector: 'app-connection-member',
  templateUrl: './connection-member.component.html',
  styleUrls: ['./connection-member.component.css']
})
export class ConnectionMemberComponent implements OnInit {	
   isCorrect:boolean;
   login: string;
   password: string;
   subscribe: any;

  constructor(private connect: ConnectionService,private router: Router){}
  

	ngOnInit(){
		this.isCorrect=true;
	} 

	recorded(event){
	} 

	logged(){
		let params: string=this.login+"/"+this.password;
		let isConnected=false;
		console.log(this.login);
		console.log(this.password);
		console.log(params);
		console.log(this.router);
		let observable: Observable<any> = this.connect.getMemberAccount(params);
		observable.subscribe({
		next(res){console.log(res);/*this.router.navigate([{'outlets':{'account-outlet':['account']}}]);*/},
		error(err){console.log("rien reçu!")}
		});
		this.router.navigate([{'outlets':{'account-outlet':['account']}}]);
	}
}


