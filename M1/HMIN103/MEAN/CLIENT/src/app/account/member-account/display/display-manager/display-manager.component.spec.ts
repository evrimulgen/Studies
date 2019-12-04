import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { DisplayManagerComponent } from './display-manager.component';

describe('DisplayManagerComponent', () => {
  let component: DisplayManagerComponent;
  let fixture: ComponentFixture<DisplayManagerComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ DisplayManagerComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(DisplayManagerComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
