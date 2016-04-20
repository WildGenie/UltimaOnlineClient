//
//  SkillAsset.hpp
//  UltimaOnlineCore
//
//  Created by Hercules Junior on 4/10/16.
//  Copyright © 2016 Hercules Junior. All rights reserved.
//

#ifndef CORE_ASSET_Skills_h
#define CORE_ASSET_Skills_h

#import <vector>
#import "Asset.h"
#import "Skill.h"

namespace core {
    namespace asset {
        class SkillGroup;
        class Skill;
        class Skills: public Asset {
        public:
            Skills();
            ~Skills();
        private:
            core::asset::SkillGroup *_skillGroups;
            core::asset::Skill *_skills;
            int _count;
        };
    }
}

#endif /* CORE_ASSET_Skills_h */