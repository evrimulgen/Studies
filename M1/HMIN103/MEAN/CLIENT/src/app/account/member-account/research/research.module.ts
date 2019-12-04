import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { HttpClientModule } from '@angular/common/http';
import { FormsModule }   from '@angular/forms';

import { ResearchManagerComponent } from './research-manager/research-manager.component';

@NgModule({
  declarations: [ResearchManagerComponent],
  imports: [ BrowserModule, HttpClientModule, FormsModule],
  exports: [ ResearchManagerComponent ],
  providers: [],
  bootstrap: []
})
export class ResearchModule { }
