import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { HttpClientModule } from '@angular/common/http';

import { DisplayManagerComponent } from './display-manager/display-manager.component';

@NgModule({
  declarations: [DisplayManagerComponent],
  imports: [ BrowserModule, HttpClientModule ],
  exports: [ DisplayManagerComponent ],
  providers: [],
  bootstrap: []
})
export class DisplayModule { }
