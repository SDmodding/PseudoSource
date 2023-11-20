// File Line: 60
// RVA: 0x641E90
void UserManager::CreateInstance(void)
{
  UserManager *v0; // rax

  if ( !UserManager::mInstance )
  {
    v0 = (UserManager *)UFG::qMalloc(4ui64, "UserManager", 0i64);
    if ( v0 )
      v0->mCurrentState = -1;
    UserManager::mInstance = v0;
  }
}

// File Line: 68
// RVA: 0x641EE0
UserManager *__fastcall UserManager::GetInstance()
{
  return UserManager::mInstance;
}

