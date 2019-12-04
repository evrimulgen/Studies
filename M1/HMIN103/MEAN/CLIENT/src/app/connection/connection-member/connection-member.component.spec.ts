import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { ConnectionMemberComponent } from './connection-member.component';

describe('ConnectionMemberComponent', () => {
  let component: ConnectionMemberComponent;
  let fixture: ComponentFixture<ConnectionMemberComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ ConnectionMemberComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(ConnectionMemberComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
