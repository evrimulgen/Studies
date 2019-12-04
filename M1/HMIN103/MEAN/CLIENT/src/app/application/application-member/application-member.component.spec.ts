import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { ApplicationMemberComponent } from './application-member.component';

describe('ApplicationMemberComponent', () => {
  let component: ApplicationMemberComponent;
  let fixture: ComponentFixture<ApplicationMemberComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ ApplicationMemberComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(ApplicationMemberComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
