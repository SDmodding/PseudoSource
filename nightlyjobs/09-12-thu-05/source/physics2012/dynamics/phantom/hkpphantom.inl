// File Line: 22
// RVA: 0xD67370
__int64 __fastcall hkpPhantom::fireCollidableAdded(hkpPhantom *this, hkpCollidable *collidable)
{
  int v2; // eax
  hkpPhantom *v3; // rdi
  __int64 v4; // rbx
  hkpPhantomOverlapListener *v5; // rcx
  hkpPhantom *v7; // [rsp+20h] [rbp-28h]
  hkpCollidable *v8; // [rsp+28h] [rbp-20h]
  unsigned int v9; // [rsp+30h] [rbp-18h]

  v2 = this->m_overlapListeners.m_size;
  v3 = this;
  v8 = collidable;
  --v2;
  v7 = this;
  v9 = 0;
  v4 = v2;
  if ( v2 < 0 )
    return 0i64;
  do
  {
    v5 = v3->m_overlapListeners.m_data[v4];
    if ( v5 )
      v5->vfptr->collidableAddedCallback(v5, (hkpCollidableAddedEvent *)&v7);
    --v4;
  }
  while ( v4 >= 0 );
  return v9;
}

