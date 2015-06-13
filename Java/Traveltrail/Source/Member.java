/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package traveltrail;

import java.util.ArrayList;
import traveltrail.bases.MemberBase;
import traveltrail.records.MemberRecord;

/**
 *
 * @author Wap
 */
public class Member {
    
    private MemberBase base;
    private ArrayList<Stat> stats;
    private ArrayList<Relationship> relationships;

    Member() {
        //Create brand new Member through user input
    }

    Member(MemberRecord memberRecord, ArrayList<Relationship> relationships, ArrayList<Stat> stats) {
        //Create Member from loaded records
    }
}
