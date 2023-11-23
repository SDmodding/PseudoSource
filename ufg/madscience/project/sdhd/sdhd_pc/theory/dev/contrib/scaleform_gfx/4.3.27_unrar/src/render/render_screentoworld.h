// File Line: 35
// RVA: 0x89C9F0
void __fastcall Scaleform::Render::ScreenToWorld::ScreenToWorld(Scaleform::Render::ScreenToWorld *this)
{
  this->Sx = 3.4028235e38;
  this->Sy = 3.4028235e38;
  this->LastX = 3.4028235e38;
  this->LastY = 3.4028235e38;
  memset(&this->MatProj, 0, sizeof(this->MatProj));
  this->MatProj.M[0][0] = 1.0;
  this->MatProj.M[1][1] = 1.0;
  this->MatProj.M[2][2] = 1.0;
  this->MatProj.M[3][3] = 1.0;
  memset(&this->MatView, 0, sizeof(this->MatView));
  this->MatView.M[0][0] = 1.0;
  this->MatView.M[1][1] = 1.0;
  this->MatView.M[2][2] = 1.0;
  memset(&this->MatWorld, 0, sizeof(this->MatWorld));
  this->MatWorld.M[0][0] = 1.0;
  this->MatWorld.M[1][1] = 1.0;
  this->MatWorld.M[2][2] = 1.0;
  memset(&this->MatInvProj, 0, sizeof(this->MatInvProj));
  this->MatInvProj.M[0][0] = 1.0;
  this->MatInvProj.M[1][1] = 1.0;
  this->MatInvProj.M[2][2] = 1.0;
  this->MatInvProj.M[3][3] = 1.0;
}

