// File Line: 301
// RVA: 0x1EDF90
void __fastcall UFG::qQuaternion::qQuaternion(UFG::qQuaternion *this, UFG::qQuaternion *v)
{
  *(UFG::qVector4 *)this = (UFG::qVector4)*v;
}

// File Line: 431
// RVA: 0x20F80
bool __fastcall UFG::qMatrix44::operator==(UFG::qMatrix44 *this, UFG::qMatrix44 *b)
{
  return b->v0.x == this->v0.x
      && b->v0.y == this->v0.y
      && b->v0.z == this->v0.z
      && b->v0.w == this->v0.w
      && b->v1.x == this->v1.x
      && b->v1.y == this->v1.y
      && b->v1.z == this->v1.z
      && b->v1.w == this->v1.w
      && b->v2.x == this->v2.x
      && b->v2.y == this->v2.y
      && b->v2.z == this->v2.z
      && b->v2.w == this->v2.w
      && b->v3.x == this->v3.x
      && b->v3.y == this->v3.y
      && b->v3.z == this->v3.z
      && b->v3.w == this->v3.w;
}

