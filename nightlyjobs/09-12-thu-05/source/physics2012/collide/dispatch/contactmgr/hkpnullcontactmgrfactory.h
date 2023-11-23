// File Line: 26
// RVA: 0xD5EA80
hkpNullContactMgr *__fastcall hkpNullContactMgrFactory::createContactMgr(
        hkpNullContactMgrFactory *this,
        hkpCollidable *a,
        hkpCollidable *b,
        hkpCollisionInput *env)
{
  return &this->m_contactMgr;
}

