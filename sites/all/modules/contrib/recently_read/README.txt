// $Id$

== SUMMARY ==

The Recently Read module displays the history of recently read Entity
a particular user has viewed. Each authenticated user has its own history 
recorded, so this module may be useful i.e. for displaying recently viewed 
products on the e-commerce site. The history is displayed as a block and each 
content type gets its own block.

If you need more flexibility, this module can be replaced by properly configured
Flag, Rules and Views modules. Check out the following links for more details:
* http://drupal.org/node/405754
* http://jan.tomka.name/blog/list-recently-viewed-nodes-drupal

For a full description of the module, visit the project page:
  http://drupal.org/sandbox/pgorecki/1080970

To submit bug reports and feature suggestions, or to track changes:
  http://drupal.org/project/issues/1080970


== REQUIREMENTS ==

None.


== INSTALLATION ==

* Install as usual, see http://drupal.org/node/70151 for further information.
* Module depend on module views, entity, session_api. Pls download it accordingly.
  http://drupal.org/project/views
  http://drupal.org/project/entity
  http://drupal.org/project/session_api


== CONFIGURATION ==

  Just an example for recently viewed nodes. Actually, all the recently read entity can support.
  1: Add a new views based on node(content).
  2: set a relationship "Recently Read".
  3: Add filter:
     (Recently Read) Recently Read: Current (Yes)
     (Recently Read) Recently Read: entity type (= Node)
  4: Add sort:
     (Recently Read) Recently Read: Recently Read Date (desc)
  5: Maybe you can create a views block. and in block configuration page, you can place this block
  where you want. 
     Or you can use context module, to make a better block visibility config.

  If you use this module in your commerce site, you can create recently read orders based on this tutorial.


== CONTACT ==

Current maintainer:
* Przemyslaw Gorecki (pgorecki) - http://drupal.org/user/642012
* Terry Zhang (zterry95) - http://drupal.org/user/1952394
