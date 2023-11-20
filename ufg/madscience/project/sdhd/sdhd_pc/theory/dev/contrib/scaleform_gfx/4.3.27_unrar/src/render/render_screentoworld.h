// File Line: 35
// RVA: 0x89C9F0
void __fastcall Scaleform::Render::ScreenToWorld::ScreenToWorld(Scaleform::Render::ScreenToWorld *this)
{
  Scaleform::Render::ScreenToWorld *v1; // rdi

  v1 = this;
  this->Sx = 3.4028235e38;
  this->Sy = 3.4028235e38;
  this->LastX = 3.4028235e38;
  this->LastY = 3.4028235e38;
  memset(&this->MatProj, 0, 0x40ui64);
  v1->MatProj.M[0][0] = 1.0;
  v1->MatProj.M[1][1] = 1.0;
  v1->MatProj.M[2][2] = 1.0;
  v1->MatProj.M[3][3] = 1.0;
  memset(&v1->MatView, 0, 0x30ui64);
  v1->MatView.M[0][0] = 1.0;
  v1->MatView.M[1][1] = 1.0;
  v1->MatView.M[2][2] = 1.0;
  memset(&v1->MatWorld, 0, 0x30ui64);
  v1->MatWorld.M[0][0] = 1.0;
  v1->MatWorld.M[1][1] = 1.0;
  v1->MatWorld.M[2][2] = 1.0;
  memset(&v1->MatInvProj, 0, 0x40ui64);
  v1->MatInvProj.M[0][0] = 1.0;
  v1->MatInvProj.M[1][1] = 1.0;
  v1->MatInvProj.M[2][2] = 1.0;
  v1->MatInvProj.M[3][3] = 1.0;
}

