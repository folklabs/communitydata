<?php
/**
 * @file
 * openviz_admin.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function openviz_admin_default_rules_configuration() {
  $items = array();
  $items['rules_ol_admin_email_reported_abuse'] = entity_import('rules_config', '{ "rules_ol_admin_email_reported_abuse" : {
      "LABEL" : "OL Admin: Email reported abuse",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "openviz" ],
      "REQUIRES" : [ "rules", "flag" ],
      "ON" : { "flag_flagged_ol_report_abuse" : [] },
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "4" : "4" } },
            "subject" : "[[site:name]]: Abusive content reported: [flagged-node:title]",
            "message" : "See [flagged-node:url]."
          }
        }
      ]
    }
  }');
  $items['rules_ol_email_admin_for_user_registration'] = entity_import('rules_config', '{ "rules_ol_email_admin_for_user_registration" : {
      "LABEL" : "Email admin for user registration",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "openviz" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [] },
      "DO" : [
        { "mail" : {
            "to" : "[site:mail]",
            "subject" : "New user registered: [account:name]",
            "message" : "New user registered: [account:name]\\r\\n\\r\\n[account:url]",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_user_edit'] = entity_import('rules_config', '{ "rules_user_edit" : {
      "LABEL" : "User edit",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_update" : [] },
      "DO" : []
    }
  }');
  return $items;
}
