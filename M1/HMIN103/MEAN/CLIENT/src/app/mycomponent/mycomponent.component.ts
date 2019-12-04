import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-mycomponent',
  templateUrl: './mycomponent.component.html',
  styleUrls: ['./mycomponent.component.css']
})
export class MycomponentComponent implements OnInit {
	message: string = "Un message à afficher";		
	constructor() {}
	ngOnInit() {
		console.log(this.message);
	}

}
