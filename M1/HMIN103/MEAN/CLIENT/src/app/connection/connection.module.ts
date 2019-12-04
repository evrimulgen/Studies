import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { HttpClientModule } from '@angular/common/http';
import { FormsModule }   from '@angular/forms';
import { AppRoutingModule } from '../app-routing.module';
import { RouterModule } from '@angular/router';

import { ConnectionMemberComponent } from './connection-member/connection-member.component';
import { ConnectionService } from './connection.service';

@NgModule({
  declarations: [ ConnectionMemberComponent ],
  imports: [ AppRoutingModule,BrowserModule, HttpClientModule, FormsModule ],
  exports: [ ConnectionMemberComponent, RouterModule],
  providers: [ ConnectionService ],
  bootstrap: []
})
export class ConnectionModule { }
