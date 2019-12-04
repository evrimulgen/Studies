import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { HttpClientModule } from '@angular/common/http';


import { DeleteManagerComponent } from './delete-manager/delete-manager.component';

@NgModule({
  declarations: [DeleteManagerComponent],
  imports: [ BrowserModule, HttpClientModule ],
  exports: [ DeleteManagerComponent ],
  providers: [  ],
  bootstrap: []
})
export class DeleteModule { }
