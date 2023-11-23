// File Line: 22
// RVA: 0xD67370
__int64 __fastcall hkpPhantom::fireCollidableAdded(hkpPhantom *this, hkpCollidable *collidable)
{
  int m_size; // eax
  __int64 v4; // rbx
  hkpPhantomOverlapListener *v5; // rcx
  __int64 v7[2]; // [rsp+20h] [rbp-28h] BYREF
  unsigned int v8; // [rsp+30h] [rbp-18h]

  m_size = this->m_overlapListeners.m_size;
  v7[1] = (__int64)collidable;
  --m_size;
  v7[0] = (__int64)this;
  v8 = 0;
  v4 = m_size;
  if ( m_size < 0 )
    return 0i64;
  do
  {
    v5 = this->m_overlapListeners.m_data[v4];
    if ( v5 )
      v5->vfptr->collidableAddedCallback(v5, (hkpCollidableAddedEvent *)v7);
    --v4;
  }
  while ( v4 >= 0 );
  return v8;
}

