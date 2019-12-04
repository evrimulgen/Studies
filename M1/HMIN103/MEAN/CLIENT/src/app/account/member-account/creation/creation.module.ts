import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { HttpClientModule } from '@angular/common/http';

import { CreationManagerComponent } from './creation-manager/creation-manager.component';

@NgModule({
  declarations: [CreationManagerComponent],
  imports: [ BrowserModule, HttpClientModule ],
  exports: [ CreationManagerComponent  ],
  providers: [],
  bootstrap: []
})
export class CreationModule { }
