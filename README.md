# KIT-201

A 2D platformer SFML/C++ game project created by Aziz Önder (22050141021), Uğur Kuş (22050111002), and Emin Salih Açıkgöz (22050111032).

## Contributions

**Aziz Önder:**
- Bullet, CollisionManager, PhysicsManager, Entity, Player, Enemy, EnemyTypeA, EnemyTypeB, TileMap, World, and Game classes
- Animations
- Selection and editing of texture assets (assets were pre-made)
- Environment (GitHub repository) and library setup

**Uğur Kuş:**
- Camera and SoundManager classes 
- Minor adjustments made on Player, World, Game, and StateManager classes
- Level Design
- Doxygen setup

**Emin Salih Açıkgöz:**
- StateManager and TileMapParser classes
- Revised Game and Camera classes
- Text display within StateManager, using a font file
- Documentation for header files

## How to run KIT-201?
### Running from the .exe
Unzip 'KIT-201.zip' and execute the .exe file. If you don't have 'Microsoft Visual C++ Redistributables', it is recommended to download the latest version from Microsoft's official website.

### Running from the VisualStudio 
Clone the repository from GitHub to obtain the necessary project files, including essential SFML files and configurations required for Visual Studio. Then, simply run it from the Visual Studio.
  
***NOTE:*** To ensure compatibility with both 32-bit and 64-bit systems, we used the 32-bit version of SFML. Thus, when running the game from Visual Studio, select 'x86' as the 'solution platform' in Visual Studio settings.  

***NOTE:*** To view doxygen page, open the index.html from html folder.

## Controls
- **LeftMouseButton:** Shoot laser bullet
- **A:** Move left
- **D:** Move right
- **Space:** Jump
- **P:** Pause/resume the game
- **ESC:** Quit the game
