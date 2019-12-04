import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { CreationManagerComponent } from './creation-manager.component';

describe('CreationManagerComponent', () => {
  let component: CreationManagerComponent;
  let fixture: ComponentFixture<CreationManagerComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ CreationManagerComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(CreationManagerComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
