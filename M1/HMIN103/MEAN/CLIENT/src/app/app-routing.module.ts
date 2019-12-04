import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { MemberAccountComponent } from './account/member-account/member-account.component';
import { ApplicationMemberComponent } from './application/application-member/application-member.component';
import { ConnectionMemberComponent } from './connection/connection-member/connection-member.component';


const routes: Routes =[
	{
		path: 'account',
		component : MemberAccountComponent,
		outlet: 'account-outlet'
	},
	{
		path: 'application',
		component: ApplicationMemberComponent,
		outlet: 'application-outlet'
	},
];

@NgModule({
  imports: [RouterModule.forRoot(routes, { enableTracing: true })],
  exports: [RouterModule]
})
export class AppRoutingModule {}
