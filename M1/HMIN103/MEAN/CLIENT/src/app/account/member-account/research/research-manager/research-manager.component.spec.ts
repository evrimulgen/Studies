import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { ResearchManagerComponent } from './research-manager.component';

describe('ResearchManagerComponent', () => {
  let component: ResearchManagerComponent;
  let fixture: ComponentFixture<ResearchManagerComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ ResearchManagerComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(ResearchManagerComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
