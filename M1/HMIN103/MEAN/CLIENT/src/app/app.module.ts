import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';

import { ConnectionModule } from './connection/connection.module';
import { ApplicationModule } from './application/application.module';
import { AccountModule } from './account/account.module';
import { AppRoutingModule } from './app-routing.module';

import { AppComponent } from './app.component';



@NgModule({
  declarations: [
    AppComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    ConnectionModule,
	  ApplicationModule,
	  AccountModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
