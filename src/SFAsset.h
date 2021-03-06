#ifndef SFASSET_H
#define SFASSET_H

#include <string>
#include <memory>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

#include "SFCommon.h"
#include "SFEvent.h"
#include "SFWindow.h"
#include "SFBoundingBox.h"

/**
 * We could create SFPlayer, SFProjectile and SFAsset which are subclasses
 * of SFAsset.  However, I've made an implementation decision to use this
 * enum to mark the type of the SFAsset.  If we add more asset types then
 * the subclassing strategy becomes a better option.
 */
enum SFASSETTYPE {SFASSET_DEAD, SFASSET_PLAYER, SFASSET_PROJECTILE, SFASSET_ALIEN, SFASSET_COIN, SFASSET_STAR, SFASSET_SCORE_TITLE, SFASSET_TOP_BAR, SFASSET_SCORE_0, SFASSET_SCORE_1, SFASSET_SCORE_2, SFASSET_SCORE_3, SFASSET_SCORE_4, SFASSET_SCORE_5, SFASSET_SCORE_6, SFASSET_SCORE_7, SFASSET_SCORE_8, SFASSET_SCORE_9, SFASSET_SCORE_00, SFASSET_SCORE_10, SFASSET_SCORE_20, SFASSET_SCORE_30, SFASSET_SCORE_40, SFASSET_SCORE_50, SFASSET_SCORE_60, SFASSET_SCORE_70, SFASSET_SCORE_80, SFASSET_SCORE_90, SFASSET_GAME_OVER, SFASSET_GAME_WIN};

class SFAsset {
public:
  SFAsset(const SFASSETTYPE, const std::shared_ptr<SFWindow>);
  SFAsset(const SFAsset&);
  virtual ~SFAsset();

  virtual void      SetPosition(Point2 &);
  virtual Point2    GetPosition();
  virtual SFAssetId GetId();
  virtual void      OnRender();
  virtual void      GoEast();
  virtual void      GoWest();
  virtual void      GoNorth();
  virtual void      GoSouth();
  virtual void      GoSouthStars();
  virtual void      PlayerGoNorth();
  virtual void      PlayerGoSouth();
  virtual void      SetNotAlive();
  virtual bool      IsAlive();
  virtual void      HandleCollision();

  virtual bool                      CollidesWith(shared_ptr<SFAsset>);
  virtual shared_ptr<SFBoundingBox> GetBoundingBox();
private:
  // it would be nice if we could make this into a smart pointer,
  // but, because we need to call SDL_FreeSurface on it, we can't.
  // (or we could use a std::shared_ptr with a custom Deleter, but
  // that's a little too much right now)
  SDL_Texture               * sprite;
  shared_ptr<SFBoundingBox>   bbox;
  SFASSETTYPE                 type;
  SFAssetId                   id;
  std::shared_ptr<SFWindow>   sf_window;

  static int SFASSETID;
};

#endif
