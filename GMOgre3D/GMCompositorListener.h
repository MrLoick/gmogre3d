/*
--------------------------------------------------------------------------------
GMOgre3D - Wrapper of the OGRE 3D library for Game Maker

Copyright (C) 2010 Robert Geiman
                   <robgeiman@gmail.com>

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place - Suite 330, Boston, MA 02111-1307, USA, or go to
http://www.gnu.org/copyleft/lesser.txt.
--------------------------------------------------------------------------------
*/

#ifndef GMOGRE_COMPOSITORLISTENER_H
#define GMOGRE_COMPOSITORLISTENER_H


class GMCompositorListener: public Ogre::CompositorInstance::Listener
{
public:
   GMCompositorListener();

   virtual void notifyMaterialSetup(Ogre::uint32 pass_id, Ogre::MaterialPtr &mat);
   virtual void notifyMaterialRender(Ogre::uint32 pass_id, Ogre::MaterialPtr &mat);

   void SetNotifyMaterialSetupCallback(int func);
   void SetNotifyMaterialRenderCallback(int func);

protected:
   int mNotifyMaterialSetupCallback;
   int mNotifyMaterialRenderCallback;
};

#endif
