import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { HttpClientModule } from '@angular/common/http';
import { FormsModule }   from '@angular/forms';
import { AppRoutingModule } from '../app-routing.module';

import { ApplicationMemberComponent } from './application-member/application-member.component';
import { ApplicationService } from './application.service';

@NgModule({
  declarations: [ ApplicationMemberComponent ],
  imports: [ BrowserModule, HttpClientModule, AppRoutingModule, FormsModule ],
  exports: [ ApplicationMemberComponent ],
  providers: [ ApplicationService ],
  bootstrap: []
})
export class ApplicationModule { }
