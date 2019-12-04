import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { HttpClientModule } from '@angular/common/http';


import { CreationModule } from './member-account/creation/creation.module';
import { ResearchModule } from './member-account/research/research.module';
import { DeleteModule } from './member-account/delete/delete.module'
import { DisplayModule } from './member-account/display/display.module'

import { MemberAccountComponent } from './member-account/member-account.component';

@NgModule({
  declarations: [MemberAccountComponent],
  imports: [ 
	BrowserModule, 
 	HttpClientModule,
 	CreationModule,
	ResearchModule,
	DeleteModule,
	DisplayModule
  ],
  exports: [ MemberAccountComponent],
  providers: [],
  bootstrap: []
})
export class AccountModule { }
